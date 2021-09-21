#pragma once

#include <Type3.h>

namespace Bloop {
    using namespace CXUtils;

    /// <summary>
    ///		The info returned after ray casting
    /// </summary>
    template<typename TRenderObject>
    struct RayCastInfo {
    public:
        const Float3 endPoint;
        const Float3 direction;
        const float distance;
        const TRenderObject *renderObject;

    public:
        RayCastInfo(const Float3 &direction, const float &distance) :
                endPoint(0, 0, 0), direction(direction), distance(distance), renderObject(nullptr) {

        }

        RayCastInfo(const Float3 &endPoint, const Float3 &direction, const float &distance,
                    const TRenderObject *renderObject) :
                endPoint(endPoint), direction(direction), distance(distance), renderObject(renderObject) {}

    public:
        [[nodiscard]] bool DidntHit() const {
            return renderObject == nullptr;
        }
    };
}


