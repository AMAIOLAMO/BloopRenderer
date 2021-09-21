#include "SDFPlainMaterial.h"

using namespace Bloop;

SDFPlainMaterial::SDFPlainMaterial(const Color8& color) : SDFColorMaterial(color) {}

Color8 SDFPlainMaterial::RenderFragment(const RayCastInfo& rayInfo) const
{
	return color;
}
