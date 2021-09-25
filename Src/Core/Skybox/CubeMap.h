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

    public:
        CubeMap( const TImage& image ) : _data( image )
        { }

    public:
        virtual Color8 Sample( const Float3& direction ) const = 0;
    };
}
