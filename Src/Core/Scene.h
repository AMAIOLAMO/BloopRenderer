#pragma once

#include <vector>
#include <iostream>
#include <memory>

#include "RenderObjects/RenderObject.h"

namespace Bloop
{
	/// <summary>
	///		The main entry of a scene
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
		///		Adds a SceneObject to the scene <br/>
		///		Note that you will lose the pointer reference when adding into the scene
		/// </summary>
		Scene& Add(const std::shared_ptr<RenderObject>& renderObject);
	};
}


