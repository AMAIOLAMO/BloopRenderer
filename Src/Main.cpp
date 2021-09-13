#include <iostream>
#include <thread>
#include <filesystem>

#include "../Vendor/Plugins/Bitmap/bitmap_image.hpp"

#include "Core/Scene.h"

int main()
{
	bitmap_image resultImg(1920, 1080);

	Bloop::Scene scene;

	resultImg.save_image("C:\\Users\\alienware\\Desktop\\Work\\test.bmp");
}