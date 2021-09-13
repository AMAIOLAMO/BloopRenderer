#pragma once

#include <cmath>

namespace CXUtils
{
	template<typename Type>
	struct Type2
	{
	public:
		const Type& x, y;

	public:
		Type2(const Type& x, const Type& y) : x(x), y(y) { }
		template<typename ConvertingType>
		Type2(Type2<ConvertingType> from) : x(static_cast<Type>(from.x)), y(static_cast<Type>(from.y)) {  }

		Type SqrMagnitude() { return x * x + y * y; }

		Type Magnitude() { return sqrt(SqrMagnitude()); }

		Type Dot(const Type2<Type>& other) { return x * other.x + y * other.y; }

		Type2<Type> operator+(const Type2<Type>& other) { return Type2<Type>(x + other.x, y + other.y); }
		Type2<Type> operator-(const Type2<Type>& other) { return Type2<Type>(x - other.x, y - other.y); }

		Type2<Type> operator*(const Type value) { return Type2<Type>(x * value, y * value); }
		Type2<Type> operator/(const Type value) { return Type2<Type>(x / value, y / value); }

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
	typedef Type2<int>          Int2;
	typedef Type2<double>       Double2;

#pragma endregion
}