#include "Scene.h"

using namespace Bloop;

Scene::Scene() : _renderObjects() {  }

Scene::~Scene() {  }

void Scene::Add(const std::shared_ptr<RenderObject>& renderObject)
{
	_renderObjects.push_back(renderObject);
}
