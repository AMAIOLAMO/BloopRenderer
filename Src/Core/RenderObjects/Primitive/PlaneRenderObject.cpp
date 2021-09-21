#include "PlaneRenderObject.h"

using namespace Bloop;

PlaneRenderObject::PlaneRenderObject(const Float3 &position, SDFMaterial *material) : SDFRenderObject(position, material) {}

float PlaneRenderObject::GetDistance(const Float3 &point) const { return std::abs(_position.y - point.y); }
