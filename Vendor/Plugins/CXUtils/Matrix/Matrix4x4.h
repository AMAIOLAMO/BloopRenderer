#pragma once

#include "../Vector/Type4.h"
#include "../Vector/Type3.h"

namespace CXUtils
{
    template<typename T>
    struct Matrix4x4
    {
    public:
        union
        {
            struct
            {
                T
                        m00, m10, m20, m30, //col 0
                m01, m11, m21, m31, //col 1
                m02, m12, m22, m32, //col 2
                m03, m13, m23, m33; //col 3
            };

            struct
            {
                Type4<T> column0;
                Type4<T> column1;
                Type4<T> column2;
                Type4<T> column3;
            };

            struct
            {
                T data[];
            };
        };

    public:
        Matrix4x4( const T& m00, const T& m10, const T& m20, const T& m30,
                   const T& m01, const T& m11, const T& m21, const T& m31,
                   const T& m02, const T& m12, const T& m22, const T& m32,
                   const T& m03, const T& m13, const T& m23, const T& m33 ) :
                m00( m00 ), m01( m01 ), m02( m02 ), m03( m03 ),
                m10( m10 ), m11( m11 ), m12( m12 ), m13( m13 ),
                m20( m20 ), m21( m21 ), m22( m22 ), m23( m23 ),
                m30( m30 ), m31( m31 ), m32( m32 ), m33( m33 )
        { }

        Matrix4x4( Type4<T> column0, Type4<T> column1,
                   Type4<T> column2, Type4<T> column3 ) :
                column0( column0 ), column1( column1 ),
                column2( column2 ), column3( column3 )
        { }

    public:
        /// Transforms the (direction / rotation), position and scale of the vector
        Type3<T> Transform( const Type3<T>& vector )
        {
            const float num = (T) 1 / ((m30 * vector.x + m31 * vector.y + m32 * vector.z) + m33);

            return {
                    (m00 * vector.x + m01 * vector.y + m02 * vector.z + m03) * num,
                    (m10 * vector.x + m11 * vector.y + m12 * vector.z + m13) * num,
                    (m20 * vector.x + m21 * vector.y + m22 * vector.z + m23) * num
            };
        }

        /// Transforms the (direction / rotation) and position of the vector
        Type3<T> Transform3x4( const Type3<T>& vector )
        {
            return {
                    m00 * vector.x + m01 * vector.y + m02 * vector.z + m03,
                    m10 * vector.x + m11 * vector.y + m12 * vector.z + m13,
                    m20 * vector.x + m21 * vector.y + m22 * vector.z + m23
            };
        }

        /// Transforms the (direction / rotation) of the vector
        Type3<T> TransformDirection( const Type3<T>& vector )
        {
            return {
                    m00 * vector.x + m01 * vector.y + m02 * vector.z,
                    m10 * vector.x + m11 * vector.y + m12 * vector.z,
                    m20 * vector.x + m21 * vector.y + m22 * vector.z
            };
        }

    public:
        static Matrix4x4<T> Identity()
        {
            return {
                    (T) 1, (T) 0, (T) 0, (T) 0,
                    (T) 0, (T) 1, (T) 0, (T) 0,
                    (T) 0, (T) 0, (T) 1, (T) 0,
                    (T) 0, (T) 0, (T) 0, (T) 1
            };
        }
    };

#pragma region TypeDef

    typedef Matrix4x4<float> Float4x4;
    typedef Matrix4x4<double> Double4x4;
    typedef Matrix4x4<int> Int4x4;

#pragma endregion
}

