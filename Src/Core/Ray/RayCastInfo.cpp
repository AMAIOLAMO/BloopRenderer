#include "RayCastInfo.h"

using namespace Bloop;

RayCastInfo::RayCastInfo(const Float3& direction, const float& distance) :
	endPoint(0, 0, 0), direction(direction), distance(distance), renderObject(nullptr) {}

RayCastInfo::RayCastInfo(const Float3& endPoint, const Float3& direction, const float& distance, const RenderObject* renderObject) :
	endPoint(endPoint), direction(direction), distance(distance), renderObject(renderObject) {}

bool Bloop::RayCastInfo::DidntHit() const
{
	return renderObject == nullptr;
}
