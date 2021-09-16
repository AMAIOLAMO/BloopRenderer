#include "RayCastInfo.h"

using namespace Bloop;

RayCastInfo::RayCastInfo(const Float3& endPoint, const Float3& direction, const float& distance, const RenderObject* renderObject) :
	endPoint(endPoint), direction(direction), distance(distance), renderObject(renderObject) {}
