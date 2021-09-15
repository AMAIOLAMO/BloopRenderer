#pragma once

#include "../SDFRenderObject.h"


namespace Bloop
{
	class SphereRenderObject : public SDFRenderObject
	{
	protected:
		float _radius;

	public:
		SphereRenderObject(const Float3& position, const float& radius);

	public:
		virtual float GetDistance(const Float3& point) const override;
	};
}


