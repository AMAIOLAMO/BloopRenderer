#include "SDFScene.h"

#include "../../../Vendor/Plugins/CXUtils/Vectors/Type2.h"

using namespace Bloop;

const size_t SDFScene::MAX_RAYCAST_INTERATION = 100;
const float SDFScene::MAX_RAYMARCH_DISTANCE = 120.f;
const float SDFScene::MIN_RAYMARCH_DISTANCE = .001f;
const float SDFScene::NORMAL_EPSILON = .01f;

float SDFScene::FindClosestDistanceFromPoint(const Float3& point) const
{
	if (renderObjects.size() == 0) return std::numeric_limits<float>::max();
	//else

	float bestMin = std::numeric_limits<float>::max();

	for (size_t i = 0; i < renderObjects.size(); i++)
	{
		float dist = renderObjects[i]->GetDistance(point);
		if (dist > bestMin) continue;
		bestMin = dist;
	}

	return bestMin;
}

float SDFScene::FindClosestDistanceFromPoint(const Float3& point, int& index) const
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
	Float3 marchPoint = ray.origin;

	float endDist = 0.f;

	int selectedIndex = 0;

	for (size_t i = 0; i < MAX_RAYCAST_INTERATION; ++i)
	{
		int currentIndex;
		float dist = FindClosestDistanceFromPoint(marchPoint, currentIndex);
		endDist += dist;

		//too far
		if (endDist > MAX_RAYMARCH_DISTANCE) break;

		//marched but didn't find anything useful
		if (dist > MIN_RAYMARCH_DISTANCE)
		{
			marchPoint += ray.direction * dist;
			continue;
		}
		//else casted

		return RayCastInfo(marchPoint, ray.direction, endDist, renderObjects[currentIndex].get());
	}

	//else didn't hit anything
	return RayCastInfo(ray.direction, endDist);
}

Float3 SDFScene::GetNormal(const Float3& point) const
{
	float d = FindClosestDistanceFromPoint(point);

	return Float3(
		d - FindClosestDistanceFromPoint(point - Float3(NORMAL_EPSILON, 0, 0)),
		d - FindClosestDistanceFromPoint(point - Float3(0, NORMAL_EPSILON, 0)),
		d - FindClosestDistanceFromPoint(point - Float3(0, 0, NORMAL_EPSILON))
	).Normalized();
}
