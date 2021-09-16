#include <iostream>
#include <thread>
#include <filesystem>

#include "Core/Scene.h"
#include "Core/RenderObjects/Primitive/SphereRenderObject.h"
#include "Core/SceneRenderer/SDFSceneRenderer.h"

#include "../Vendor/Plugins/Bitmap/bitmap_image.hpp"
#include "../Vendor/Plugins/CXUtils/Diagnostics/Stopwatch.h"

#include "Core/Material/Primitive/ColorMaterial.h"
#include "Core/Scenes/SDFScene.h"
#include "Core/RenderObjects/Primitive/PlaneRenderObject.h"

int main()
{
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
		.Add(std::make_shared<PlaneRenderObject>(
			Float3(0, 0, 0),
			new ColorMaterial(Color8(255, 0, 0))
			)
		);


#pragma region Render
	sw.Start();

	for (size_t x = 0; x < imgDimension.x; x++)
	{
		for (size_t y = 0; y < imgDimension.y; y++)
		{
			resultImg.set_pixel(x, y,
				renderer.RenderPixel(
					camera, scene,
					Float2((float)x / imgDimension.x, (float)y / imgDimension.y)
				)
			);
		}
	}

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