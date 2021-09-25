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
#include <SDFPlainMaterial.h>

int main()
{
    using namespace Bloop;
    using namespace CXUtils;

    // == SETUP == //

    const std::filesystem::path currentPath = std::filesystem::current_path();

    auto skyboxPath = currentPath;

    skyboxPath.append( "Vendor/Skybox.bmp" );

    // == VARIABLES == //

    Stopwatch sw;

    UInt2 imgDimension( 1920, 1080 );

    bitmap_image resultImg( imgDimension.x, imgDimension.y );

    bitmap_image skyboxImg( skyboxPath.string() );

    RenderProfile profile( imgDimension );

    SDFSceneRenderer renderer( profile );

    SDFScene scene( 100, 200, .0005f, .001f );

    Camera camera( Float3( 0, 1, 0 ), Float3( 0, 1, 0 ), Float3( 0, 0, 1 ).Normalized(), 50 );

    scene
            .Add( std::make_shared<SphereRenderObject>(
                    Float3( 0, 1, 5 ),
                    new SDFDiffuseMaterial( Color8( 0, 255, 0 ) ),
                    1.f )
            )
            .Add( std::make_shared<SphereRenderObject>(
                    Float3( .75f * 2.f, 1, 5.1f ),
                    new SDFDiffuseMaterial( Color8( 200, 200, 0 ) ),
                    .75f )
            )
            .Add( std::make_shared<PlaneRenderObject>(
                          Float3( 0, 0, 0 ),
                          new SDFPlainMaterial( Color8( 0, 0, 200 ) )
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

    std::cout << "Render elapsed time: " << sw.Stop().count() << std::endl;

#pragma endregion

#pragma region Export | Save

    std::cout << "Saving...\n";

    auto resultImgPath = currentPath;

    resultImgPath.append( "Result.bmp" );

    const auto pathStr = currentPath.string();

    resultImg.save_image( pathStr );

    std::cout << "Saved img to currentPath: " << pathStr << std::endl;

    std::system( pathStr.c_str() );

#pragma endregion
}