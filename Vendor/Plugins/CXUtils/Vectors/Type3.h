#pragma once

#include <cmath>

namespace CXUtils
{
	template<typename Type>
	struct Type3
	{
	public:
		const Type& x, y, z;

	public:
		Type3(const Type& x, const Type& y, const Type& z) : x(x), y(y), z(z) { }
		template<typename ConvertingType>
		Type3(Type3<ConvertingType> from) : x(static_cast<Type>(from.x)), y(static_cast<Type>(from.y)), z(static_cast<Type>(from.z)) {}

		Type SqrMagnitude() { return x * x + y * y + z * z; }

		Type Magnitude() { return sqrt(SqrMagnitude()); }

		Type Dot(const Type3& other) { return x * other.x + y * other.y + z * other.z; }

		Type3<Type> Normalized()
		{
			float magnitude = Magnitude();
			return magnitude == 0.f ? Type3<Type>(0, 0, 0) : (*this) / magnitude;
		}

	public:

		Type3<Type> operator+(const Type3<Type>& other) const { return Type3<Type>(x + other.x, y + other.y, z + other.z); }
		Type3<Type> operator-(const Type3<Type>& other) const { return Type3<Type>(x - other.x, y - other.y, z - other.z); }

		Type3<Type> operator*(const Type& value) const { return Type3<Type>(x * value, y * value, z * value); }
		Type3<Type> operator/(const Type& value) const { return Type3<Type>(x / value, y / value, z / value); }

		/// <summary>
		///		Element-wise product
		/// </summary>
		Type3<Type> operator*(const Type3<Type>& other) const { return Type3<Type>(x * other.x, y * other.y, z * other.z); }

		/// <summary>
		///		Element-wise division
		/// </summary>
		Type3<Type> operator/(const Type3<Type>& other) const { return Type3<Type>(x / other.x, y / other.y, z / other.z); }
	};

#pragma region TypeDef

	typedef Type3<float>        Float3;
	typedef Type3<unsigned int> UInt3;
	typedef Type3<int>          Int3;
	typedef Type3<double>       Double3;

#pragma endregion
}