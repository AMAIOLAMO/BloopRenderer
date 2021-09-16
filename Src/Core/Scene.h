#pragma once

#include <vector>
#include <iostream>
#include <memory>

#include "Ray/Ray.h"
#include "RenderObjects/RenderObject.h"
#include "Ray/RayCastInfo.h"

namespace Bloop
{
	/// <summary>
	///		Where every RenderObject is stored
	/// </summary>
	class Scene
	{
	private:
		std::vector<std::shared_ptr<RenderObject>> _renderObjects;

	public:
		Scene();
		~Scene();

	public:
		/// <summary>
		///		Adds a SceneObject into the scene
		/// </summary>
		Scene& Add(const std::shared_ptr<RenderObject>& renderObject);
		RayCastInfo RayCast(const Ray& ray) const;
	};
}


