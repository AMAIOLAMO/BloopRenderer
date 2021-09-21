#pragma once

#include <vector>
#include <iostream>
#include <memory>

#include <Ray.h>

namespace Bloop
{
    template<typename TRenderObject>
    struct RayCastInfo;

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
		virtual ~Scene() = default;

	public:
		/// <summary>
		///		Adds a SceneObject into the scene
		/// </summary>
		Scene& Add(const std::shared_ptr<T>& renderObject)
		{
			renderObjects.push_back(renderObject);
			return (*this);
		}

		virtual RayCastInfo<T> RayCast(const Ray& ray) const = 0;
	};
}



