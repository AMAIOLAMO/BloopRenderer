#pragma once

#include "CubeMap.h"
#include <bitmap_image.hpp>

namespace Bloop
{
    class BMPCubeMap : public CubeMap<bitmap_image>
    {
    public:
        BMPCubeMap( const bitmap_image& image, const size_t& side );

    public:
        [[nodiscard]] Color8 Sample(const Float3& direction) const override;
    };
}