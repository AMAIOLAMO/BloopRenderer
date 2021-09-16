#pragma once

#include "RenderObject.h"

namespace Bloop
{
	/// <summary>
	///		An SDF (Signed distance function) driven render object
	/// </summary>
	class SDFRenderObject : public RenderObject
	{
	public:
		SDFRenderObject(const Float3& position, Material* material);

	public:
		virtual float GetDistance(const Float3& point) const = 0;
	};
}


