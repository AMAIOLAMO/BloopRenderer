#pragma once

#include "../Vectors/Type3.h"

namespace CXUtils
{
	/// <summary>
	///		Represents 3 color channels in byte
	/// </summary>
	struct Color8
	{
	public:
		union
		{
			struct
			{
				byte r, g, b;
			};

			Byte3 byte3;
		};
		
	public:
		Color8(const byte& r, const byte& g, const byte& b);
		Color8(const Byte3& vector);

	public:
		Color8 operator+(const Color8& other) const;
		Color8 operator-(const Color8& other) const;

		Color8 operator*(const byte& value) const;
		Color8 operator/(const byte& value) const;
	};
}


