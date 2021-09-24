#pragma once

#include "../Utils/CommonTypeDef.h"

namespace CXUtils
{
    template<typename Type>
    struct Type4
    {
    public:
        Type x, y, z, w;

    public:
        Type4() : x( 0 ), y( 0 ), z( 0 ), w( 0 )
        { }

        Type4( const Type& x, const Type& y, const Type& z, const Type& w ) : x( x ), y( y ), z( z ), w( w )
        { }
    };

#pragma region TypeDef

    typedef Type4<float> Float4;
    typedef Type4<double> Double4;
    typedef Type4<byte> Byte4;
    typedef Type4<unsigned int> UInt4;
    typedef Type4<int> Int4;

#pragma endregion
}
