#pragma once

#include <vector>
#include <iostream>
#include <memory>

#include "Ray/Ray.h"
#include "Ray/RayCastInfo.h"

namespace Bloop
{
	/// <summary>
	///		Where every RenderObject is stored
	/// </summary>
	template<typename T>
	class Scene
	{
	protected:
		std::vector<std::shared_ptr<T>> renderObjects;

	protected:
		Scene() : renderObjects() { }
		virtual ~Scene() { }

	public:
		/// <summary>
		///		Adds a SceneObject into the scene
		/// </summary>
		Scene& Add(const std::shared_ptr<T>& renderObject)
		{
			renderObjects.push_back(renderObject);
			return (*this);
		}

		virtual RayCastInfo RayCast(const Ray& ray) const = 0;
	};
}



