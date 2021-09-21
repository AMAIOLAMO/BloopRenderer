#pragma once

#include <SDFRenderObject.h>

namespace Bloop {
    class PlaneRenderObject : public SDFRenderObject {
    public:
        PlaneRenderObject(const Float3 &position, SDFMaterial *material);

    public:
        [[nodiscard]] float GetDistance(const Float3 &point) const override;
    };
}
