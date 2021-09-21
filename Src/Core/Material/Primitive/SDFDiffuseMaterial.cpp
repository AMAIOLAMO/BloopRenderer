#include "SDFDiffuseMaterial.h"

#include <RayCastInfo.h>
#include <SDFScene.h>

using namespace Bloop;

SDFDiffuseMaterial::SDFDiffuseMaterial(const Color8 &color) : SDFColorMaterial{color} {}

const Float3 _fakeLightDirection(Float3{0, 1, -1}.Normalized());

Color8 SDFDiffuseMaterial::RenderFragment(const RayCastInfo<SDFRenderObject> &rayInfo, const SDFScene &scene) const {
    float diffuse = std::fmax(_fakeLightDirection.Dot(scene.GetNormal(rayInfo.endPoint)), .1f);

    float r = color.r / 255.f * diffuse,
            g = color.g / 255.f * diffuse,
            b = color.b / 255.f * diffuse;

    return {(byte) (r * 255.f), (byte) (g * 255.f), (byte) (b * 255.f)};
}