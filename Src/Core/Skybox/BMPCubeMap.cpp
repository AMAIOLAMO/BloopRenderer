#include "BMPCubeMap.h"

using namespace Bloop;

BMPCubeMap::BMPCubeMap( const bitmap_image& image, const size_t& side ) : CubeMap( image, side )
{ }

Color8 BMPCubeMap::Sample( const Float3& direction ) const
{

}