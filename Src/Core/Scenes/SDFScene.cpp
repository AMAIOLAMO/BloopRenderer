#include "SDFScene.h"

#include "../../../Vendor/Plugins/CXUtils/Vectors/Type2.h"

using namespace Bloop;

const size_t SDFScene::MaxRayCastDistance = 100;
const float SDFScene::MaxRayMarchDistance = 120.f;
const float SDFScene::MinRayMarchDistance = .001f;
const float SDFScene::NormalEpsilon = .01f;

float SDFScene::FindClosestDistanceFromPoint(const Float3 &point) const {
    if (renderObjects.empty()) return std::numeric_limits<float>::max();
    //else

    float bestMin = std::numeric_limits<float>::max();

    for(const auto& renderObject : renderObjects)
    {
        float dist = renderObject->GetDistance(point);
        if (dist > bestMin) continue;
        bestMin = dist;
    }

    /*for (size_t i = 0; i < renderObjects.size(); i++) {

    }*/

    return bestMin;
}

float SDFScene::FindClosestDistanceFromPoint(const Float3 &point, size_t &index) const {
    if (renderObjects.empty()) return std::numeric_limits<float>::max();
    //else

    float bestMin = std::numeric_limits<float>::max();

    for (size_t i = 0; i < renderObjects.size(); i++) {
        float dist = renderObjects[i]->GetDistance(point);
        if (dist > bestMin) continue;
        bestMin = dist;
        index = i;
    }

    return bestMin;
}

RayCastInfo SDFScene::RayCast(const Ray &ray) const {
    Float3 marchPoint = ray.origin;

    float endDist = 0.f;

    for (size_t i = 0; i < MaxRayCastDistance; ++i) {
        size_t currentIndex;
        float dist = FindClosestDistanceFromPoint(marchPoint, currentIndex);
        endDist += dist;

        //too far
        if (endDist > MaxRayMarchDistance) break;

        //marched but didn't find anything useful
        if (dist > MinRayMarchDistance) {
            marchPoint += ray.direction * dist;
            continue;
        }
        //else casted

        return {marchPoint, ray.direction, endDist, renderObjects[currentIndex].get()};
    }

    //else didn't hit anything
    return {ray.direction, endDist};
}

Float3 SDFScene::GetNormal(const Float3 &point) const {
    float d = FindClosestDistanceFromPoint(point);

    return Float3(
            d - FindClosestDistanceFromPoint(point - Float3(NormalEpsilon, 0, 0)),
            d - FindClosestDistanceFromPoint(point - Float3(0, NormalEpsilon, 0)),
            d - FindClosestDistanceFromPoint(point - Float3(0, 0, NormalEpsilon))
    ).Normalized();
}
