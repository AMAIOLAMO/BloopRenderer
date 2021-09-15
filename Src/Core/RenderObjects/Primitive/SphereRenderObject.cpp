#include "SphereRenderObject.h"

using namespace Bloop;

SphereRenderObject::SphereRenderObject(const Float3& position, const float& radius) : SDFRenderObject(position), _radius(radius) {}

float SphereRenderObject::GetDistance(const Float3& point) const
{
	return (point + _position).Magnitude() - _radius;
}
