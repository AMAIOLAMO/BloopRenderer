#include "RayCastInfo.h"

using namespace Bloop;

RayCastInfo::RayCastInfo(const float& distance) :
	endPoint(0, 0, 0), distance(distance), renderObject(nullptr) {}

RayCastInfo::RayCastInfo(const Float3& endPoint, const float& distance, const RenderObject* renderObject) :
	endPoint(endPoint), distance(distance), renderObject(renderObject) {}

bool Bloop::RayCastInfo::DidntHit() const
{
	return renderObject == nullptr;
}
