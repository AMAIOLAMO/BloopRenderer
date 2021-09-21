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

			struct
			{
				byte red, green, blue;
			};

			Byte3 byte3;
		};
		
	public:
		Color8(const byte& r, const byte& g, const byte& b);
        Color8(const Color8& other);

		explicit Color8(const Byte3& vector);
		explicit Color8(const byte& grayscale);

	public:
		Color8 operator+(const Color8& other) const;
		Color8 operator-(const Color8& other) const;

		Color8 operator*(const byte& value) const;
		Color8 operator/(const byte& value) const;
	};
}


