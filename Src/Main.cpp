#include <iostream>
#include <thread>
#include <filesystem>

#include <Scene.h>
#include <SphereRenderObject.h>
#include <SDFSceneRenderer.h>

#include <bitmap_image.hpp>
#include <Stopwatch.h>

#include <SDFDiffuseMaterial.h>

int main() {
    using namespace Bloop;
    using namespace CXUtils;

    Stopwatch sw;

    UInt2 imgDimension(1920, 1080);

    bitmap_image resultImg(imgDimension.x, imgDimension.y);

    RenderProfile profile(imgDimension);

    SDFSceneRenderer renderer(profile);

    SDFScene scene;

    Camera camera(Float3(0, 0, 0), Float3(0, 0, 1));

    scene
            .Add(std::make_shared<SphereRenderObject>(
                    Float3(0, 0, 5),
                    new SDFDiffuseMaterial(Color8(0, 255, 0)),
                    1.f)
            )
            .Add(std::make_shared<SphereRenderObject>(
                    Float3(.5f, 0, 5),
                    new SDFDiffuseMaterial(Color8(150, 150, 0)),
                    1.f)
            );

    std::cout << "===Start Rendering===\n";


#pragma region Render
    sw.Start();

    //NOTE: remember that bitmap_image's uv starts from top left, thus flipping the image vertically is important
    for (size_t x = 0; x < imgDimension.x; ++x) {
        for (size_t y = 0; y < imgDimension.y; ++y) {
            resultImg.set_pixel(
                    x, y, renderer.RenderFragment(
                            camera, scene,
                            Float2((float) x / imgDimension.x, (1.f - (float) y / imgDimension.y) /* Flips the image vertically*/ )
                    )
            );
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

    path.append("Result.bmp");

    resultImg.save_image(path.string());

    std::cout << "Saved img to path: " << path.string() << std::endl;

#pragma endregion
}