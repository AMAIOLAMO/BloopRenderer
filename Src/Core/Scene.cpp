#include "Scene.h"

using namespace Bloop;

Scene::Scene() : _renderObjects() {  }

Scene::~Scene() {  }

Scene& Scene::Add(const std::shared_ptr<RenderObject>& renderObject)
{
	_renderObjects.push_back(renderObject);
	return (*this);
}

RayCastInfo Scene::RayCast(const Ray& ray) const
{
	return RayCastInfo(Float3(0, 0, 0), Float3(0, 0, 0), 0, nullptr);
}
