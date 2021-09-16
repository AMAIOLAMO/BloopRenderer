#pragma once

#include "../Scene.h"
#include "../RenderObjects/Primitive/SphereRenderObject.h"

namespace Bloop
{
	class SDFScene : public Scene<SDFRenderObject>
	{
	public:
		static const size_t MAX_RAYCAST_INTERATION;
		static const float MAX_RAYMARCH_DISTANCE;
		static const float MIN_RAYMARCH_DISTANCE;

	protected:
		float FindClosestFromPoint(const Float3& point, int& index) const;

	public:
		virtual RayCastInfo RayCast(const Ray& ray) const override;
	};
}


