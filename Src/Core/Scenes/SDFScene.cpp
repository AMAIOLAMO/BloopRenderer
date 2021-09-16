#include "SDFScene.h"

using namespace Bloop;

const size_t SDFScene::MAX_RAYCAST_INTERATION = 100;
const float SDFScene::MAX_RAYMARCH_DISTANCE = 100.f;
const float SDFScene::MIN_RAYMARCH_DISTANCE = .001f;

float SDFScene::FindClosestFromPoint(const Float3& point, int& index) const
{
	if (renderObjects.size() == 0) return std::numeric_limits<float>::max();
	//else

	float bestMin = std::numeric_limits<float>::max();

	for (size_t i = 0; i < renderObjects.size(); i++)
	{
		float dist = renderObjects[i]->GetDistance(point);
		if (dist > bestMin) continue;
		bestMin = dist;
		index = i;
	}

	return bestMin;
}

RayCastInfo SDFScene::RayCast(const Ray& ray) const
{
	Float3 currentMarchPoint = ray.origin;

	float endDist = 0.f;

	int selectedIndex = 0;

	for (size_t i = 0; i < MAX_RAYCAST_INTERATION; ++i)
	{
		int currentIndex;
		float dist = FindClosestFromPoint(currentMarchPoint, currentIndex);
		endDist += dist;

		//too far
		if (endDist > MAX_RAYMARCH_DISTANCE) break;

		//marched but didn't find anything useful
		if (dist > MIN_RAYMARCH_DISTANCE)
		{
			currentMarchPoint = currentMarchPoint + ray.direction * dist;
			continue;
		}
		//else touched

		return RayCastInfo(currentMarchPoint, ray.direction, endDist, renderObjects[currentIndex].get());
	}

	//else didn't hit anything
	return RayCastInfo(currentMarchPoint, ray.direction, endDist, nullptr);
}
