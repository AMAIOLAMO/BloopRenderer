#pragma once

#include "Scene.h"
#include "../RenderObjects/SDFRenderObject.h"

namespace Bloop
{
	class SDFScene : public Scene<SDFRenderObject>
	{
	public:
		static const size_t MaxRayCastDistance;
		static const float MaxRayMarchDistance;
		static const float MinRayMarchDistance;
		static const float NormalEpsilon;

	protected:
		float FindClosestDistanceFromPoint(const Float3& point) const;
		float FindClosestDistanceFromPoint(const Float3& point, size_t& index) const;

	public:
        [[nodiscard]] Float3 GetNormal(const Float3& point) const;

		/// <summary>
		///		Shoots a ray into the scene and returns whether
		/// </summary>
		[[nodiscard]] virtual RayCastInfo RayCast(const Ray& ray) const override;
	};
}


