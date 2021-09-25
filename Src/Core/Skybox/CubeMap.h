#pragma once

#include <Color8.h>
#include <Type3.h>

namespace Bloop
{
    using namespace CXUtils;

    /// This is a box that has a sky
    template<typename TImage>
    class CubeMap
    {
    protected:
        const TImage _data;
        const size_t _side;

    public:
        CubeMap( const TImage& image, const size_t& side ) : _data( image ), _side( side )
        { }

    public:
        [[nodiscard]] virtual Color8 Sample( const Float3& direction ) const = 0;
    };
}
