#include "Color8.h"

using namespace CXUtils;

Color8::Color8(const byte& r, const byte& g, const byte& b) : r(r), g(g), b(b) {}

Color8::Color8(const Byte3& vector) : byte3(vector) {}

Color8::Color8(const byte& grayscale) : byte3(grayscale, grayscale, grayscale)
{
}

Color8 Color8::operator+(const Color8& other) const
{
	return Color8(byte3 + other.byte3);
}

Color8 Color8::operator-(const Color8& other) const
{
	return Color8(byte3 - other.byte3);
}

Color8 Color8::operator*(const byte& value) const
{
	return Color8(byte3 * value);
}

Color8 Color8::operator/(const byte& value) const
{
	return Color8(byte3 / value);
}
