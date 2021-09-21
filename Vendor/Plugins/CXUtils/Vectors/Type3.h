#pragma once

#include "../Utils/CommonTypeDef.h"

#include <cmath>

namespace CXUtils {
    template<typename Type>
    struct Type3 {
    public:
        Type x, y, z;

    public:
        Type3(const Type &x, const Type &y, const Type &z) : x{x}, y{y}, z{z} {}

        Type3(const Type3<Type> &other) : x{other.x}, y{other.y}, z{other.z} {}

        template<typename ConvertingType>
        explicit Type3(const Type3<ConvertingType> &from) : x{static_cast<Type>(from.x)}, y{static_cast<Type>(from.y)},
                                                            z{static_cast<Type>(from.z)} {}

        Type SqrMagnitude() const { return x * x + y * y + z * z; }

        Type Magnitude() const { return sqrt(SqrMagnitude()); }

        Type Dot(const Type3 &other) const { return x * other.x + y * other.y + z * other.z; }

        Type3<Type> Normalized() const {
            float magnitude = Magnitude();
            return magnitude == 0.f ? Type3<Type>(0, 0, 0) : (*this) / magnitude;
        }

    public:

        Type3<Type> operator+(const Type3<Type> &other) const {
            return Type3<Type>(x + other.x, y + other.y, z + other.z);
        }

        Type3<Type> operator-(const Type3<Type> &other) const {
            return Type3<Type>(x - other.x, y - other.y, z - other.z);
        }

        Type3<Type> &operator+=(const Type3<Type> &other) {
            x += other.x;
            y += other.y;
            z += other.z;
            return (*this);
        }

        Type3<Type> &operator-=(const Type3<Type> &other) {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return (*this);
        }

        Type3<Type> operator-() const { return Type3<Type>(-x, -y, -z); }

        Type3<Type> operator*(const Type &value) const { return Type3<Type>(x * value, y * value, z * value); }

        Type3<Type> operator/(const Type &value) const { return Type3<Type>(x / value, y / value, z / value); }

        /// <summary>
        ///		Element-wise product
        /// </summary>
        Type3<Type> operator*(const Type3<Type> &other) const {
            return Type3<Type>(x * other.x, y * other.y, z * other.z);
        }

        /// <summary>
        ///		Element-wise division
        /// </summary>
        Type3<Type> operator/(const Type3<Type> &other) const {
            return Type3<Type>(x / other.x, y / other.y, z / other.z);
        }
    };

#pragma region TypeDef

    typedef Type3<float> Float3;
    typedef Type3<unsigned int> UInt3;
    typedef Type3<byte> Byte3;
    typedef Type3<int> Int3;
    typedef Type3<double> Double3;

#pragma endregion
}