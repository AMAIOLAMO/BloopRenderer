#include "BMPCubeMap.h"

#include <Type2.h>

using namespace Bloop;

BMPCubeMap::BMPCubeMap( const bitmap_image& image, const size_t& side ) : CubeMap( image, side )
{ }

BMPCubeMap::BMPCubeMap( const bitmap_image& image ) : CubeMap( image, image.width() / image.height() )
{ }

Color8 BMPCubeMap::Sample( const Float3& direction ) const
{
    const Float2 uv( direction.x * .5f + .5f, direction.y * .5f + .5f );

    Color8 result;
    _image.get_pixel( (size_t) (uv.x * _side), (size_t) (uv.y * _side), result );
    return result;
}