#pragma once

#include "../Utils/CommonTypeDef.h"

#include <cmath>

namespace CXUtils
{
	template<typename Type>
	struct Type2
	{
	public:
		const Type x, y;

	public:
		Type2(const Type& x, const Type& y) : x(x), y(y) { }
		template<typename ConvertingType>
		Type2(const Type2<ConvertingType>& from) : x(static_cast<Type>(from.x)), y(static_cast<Type>(from.y)) {  }

		Type SqrMagnitude() const { return x * x + y * y; }

		Type Magnitude() const { return sqrt(SqrMagnitude()); }

		Type2<Type> Normalized() const
		{
			float magnitude = Magnitude();
			return magnitude == 0.f ? Type2<Type>(0, 0) : (*this) / magnitude;
		}

		Type Dot(const Type2<Type>& other) { return x * other.x + y * other.y; }

		Type2<Type> operator+(const Type2<Type>& other) { return Type2<Type>(x + other.x, y + other.y); }
		Type2<Type> operator-(const Type2<Type>& other) { return Type2<Type>(x - other.x, y - other.y); }

		Type2<Type> operator*(const Type& value) { return Type2<Type>(x * value, y * value); }
		Type2<Type> operator/(const Type& value) { return Type2<Type>(x / value, y / value); }

		/// <summary>
		///		Element-wise product
		/// </summary>
		Type2<Type> operator*(const Type2<Type>& other) { return Type2<Type>(x * other.x, y * other.y); }

		/// <summary>
		///		Element-wise division
		/// </summary>
		Type2<Type> operator/(const Type2<Type>& other) { return Type2<Type>(x / other.x, y / other.y); }
	};

#pragma region TypeDef

	typedef Type2<float>        Float2;
	typedef Type2<unsigned int> UInt2;
	typedef Type2<byte>         Byte2;
	typedef Type2<int>          Int2;
	typedef Type2<double>       Double2;

#pragma endregion
}