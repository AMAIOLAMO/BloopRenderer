#include <iostream>
#include <thread>
#include <filesystem>

#include "Core/Scene.h"
#include "Core/RenderObjects/Primitive/SphereRenderObject.h"

int main()
{
	using namespace Bloop;
	using namespace CXUtils;

	Scene scene;

#define MKRenderObject(type) std::make_shared<type>()

	scene.Add(std::make_shared<SphereRenderObject>(Float3(0, 0, 0), 1.f));
}