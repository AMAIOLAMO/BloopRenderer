#include "PlainMaterial.h"

using namespace Bloop;

PlainMaterial::PlainMaterial(const Color8& color) : ColorMaterial(color) {}

Color8 PlainMaterial::RenderFragment() const
{
	return color;
}
