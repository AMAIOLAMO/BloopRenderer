#include "SphereRenderObject.h"

using namespace Bloop;

SphereRenderObject::SphereRenderObject(const Float3& position, SDFMaterial* material, const float& radius) :
	SDFRenderObject(position, material), _radius(radius) {}

float SphereRenderObject::GetDistance(const Float3& point) const
{
	return (_position - point).Magnitude() - _radius;
}
