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
		static const float NORMAL_EPSILON;

	protected:
		float FindClosestDistanceFromPoint(const Float3& point) const;
		float FindClosestDistanceFromPoint(const Float3& point, int& index) const;

	public:
		Float3 GetNormal(const Float3& point) const;

		/// <summary>
		///		Shoots a ray into the scene and returns whether
		/// </summary>
		virtual RayCastInfo RayCast(const Ray& ray) const override;
	};
}


