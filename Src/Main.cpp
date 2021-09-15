#include <iostream>
#include <thread>
#include <filesystem>

#include "Core/Scene.h"
#include "Core/RenderObjects/Primitive/SphereRenderObject.h"
#include "Core/SceneRenderer/SceneRenderer.h"

#include "../Vendor/Plugins/Bitmap/bitmap_image.hpp"

int main()
{
	using namespace Bloop;
	using namespace CXUtils;

	UInt2 imgDimension(100, 100);

	bitmap_image resultImg(imgDimension.x, imgDimension.y);

	RenderProfile profile(imgDimension);

	SceneRenderer renderer(profile);

	Scene scene;

	Camera camera(Float3(0, 0, 0), Float3(0, 0, 1));

#define MKRenderObject(type) std::make_shared<type>()

	scene.Add(std::make_shared<SphereRenderObject>(Float3(0, 0, 0), 1.f));


#pragma region Render

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

#pragma endregion


#pragma region Export | Save

	std::filesystem::path path = std::filesystem::current_path();

	path.append("Renderers/Result.bmp");

	resultImg.save_image(path.string());

	std::cout << "Saved img to path: " << path.string() << std::endl;

#pragma endregion


}