#include <iostream>
#include <thread>
#include <filesystem>

#include <Scene.h>
#include <SphereRenderObject.h>
#include <SDFSceneRenderer.h>

#include <bitmap_image.hpp>
#include <Stopwatch.h>

#include <SDFDiffuseMaterial.h>
#include <PlaneRenderObject.h>

int main()
{
    using namespace Bloop;
    using namespace CXUtils;

    Stopwatch sw;

    UInt2 imgDimension( 1920, 1080 );

    bitmap_image resultImg( imgDimension.x, imgDimension.y );

    RenderProfile profile( imgDimension );

    SDFSceneRenderer renderer( profile );

    SDFScene scene;

    Camera camera( Float3( 0, .3f, 0 ), Float3( 0, 0, 1 ) );

    scene
            .Add( std::make_shared<SphereRenderObject>(
                    Float3( 0, 0, 5 ),
                    new SDFDiffuseMaterial( Color8( 0, 255, 0 ) ),
                    1.f )
            )
            .Add( std::make_shared<SphereRenderObject>(
                    Float3( .5f, 0, 5 ),
                    new SDFDiffuseMaterial( Color8( 200, 200, 0 ) ),
                    1.f )
            )
            .Add( std::make_shared<PlaneRenderObject>(
                          Float3( 0, 0, 0 ),
                          new SDFDiffuseMaterial( Color8( 0, 0, 200 ) )
                  )
            );

    std::cout << "===Start Rendering===\n";


#pragma region Render
    sw.Start();

    {
        std::vector<Color8> colors( imgDimension.x * imgDimension.y );

        renderer.RenderImage( camera, scene, imgDimension, colors.data() );

        //NOTE: remember that bitmap_image's uv starts from top left, thus flipping the image vertically is important
        for ( size_t x = 0; x < imgDimension.x; ++x )
        {
            for ( size_t y = 0; y < imgDimension.y; ++y )
            {
                resultImg.set_pixel( x, y, colors[x + (imgDimension.y - y - 1) * imgDimension.x] );
            }
        }
    }

    /*for (size_t x = 0; x < imgDimension.x; ++x) {
        for (size_t y = 0; y < imgDimension.y; ++y) {
            resultImg.set_pixel(x, y, (byte) ((float) x / imgDimension.x * 255.f),
                                (byte) ((float) y / imgDimension.y * 255.f), 0);
        }
    }*/

    std::cout << "Render elapsed time: " << sw.Stop().count() << std::endl;

#pragma endregion

#pragma region Export | Save

    std::cout << "Saving...\n";

    std::filesystem::path path = std::filesystem::current_path();

    path.append( "Result.bmp" );

    const auto pathStr = path.string();

    resultImg.save_image( pathStr );

    std::cout << "Saved img to path: " << pathStr << std::endl;

    std::system( pathStr.c_str() );

#pragma endregion
}