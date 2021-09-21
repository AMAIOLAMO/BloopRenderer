#include "SDFDiffuseMaterial.h"

#include "../../Ray/RayCastInfo.h"

using namespace Bloop;

SDFDiffuseMaterial::SDFDiffuseMaterial(const Color8 &color) : SDFColorMaterial{color} {}

const Float3 _fakeLightDirection(Float3{0, 3, -1}.Normalized());

Color8 SDFDiffuseMaterial::RenderFragment(const RayCastInfo &rayInfo) const {
    float diffuse = std::fmax(_fakeLightDirection.Dot(-rayInfo.direction), 0.f);

    float r = color.r / 255.f * diffuse,
            g = color.g / 255.f * diffuse,
            b = color.b / 255.f * diffuse;

    return {(byte) (r * 255.f), (byte) (g * 255.f), (byte) (b * 255.f)};
}