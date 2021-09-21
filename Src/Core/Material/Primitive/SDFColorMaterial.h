#pragma once

#include <SDFMaterial.h>

namespace Bloop {
    /// <summary>
    ///		A basic material that has a color
    /// </summary>
    class SDFColorMaterial : public SDFMaterial {
    protected:
        Color8 color;

    public:
        explicit SDFColorMaterial(const Color8 &color);
    };
}