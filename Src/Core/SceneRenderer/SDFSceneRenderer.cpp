#include "SDFSceneRenderer.h"

#include <RayCastInfo.h>
#include <SDFMaterial.h>

using namespace Bloop;

SDFSceneRenderer::SDFSceneRenderer(const RenderProfile &renderProfile) : SceneRenderer(renderProfile) {}

Color8 SDFSceneRenderer::RenderFragment(const Camera &camera, const SDFScene &scene, const Float2 &uv) const {
    const float dimensionRate = (float) renderProfile.Dimension.y / renderProfile.Dimension.x;

    //TODO: this is not using camera, Dunno how to calculate that, so this is it for now
    const Float3 newViewDir = Float3(
            (uv.x - .5f) * 2.f,
            (uv.y - .5f) * 2.f * dimensionRate,
            1.f)
            .Normalized();

    const auto info = scene.RayCast(Ray(camera.position, newViewDir));

    if (info.DidntHit()) return {0, 0, 0};
    //else hit

#if 1
    return info.renderObject->GetMaterial().RenderFragment(info, scene);
#else //DEBUG
    const auto normal = scene.GetNormal(info.endPoint);

    return {(byte)((normal.x + 1.f) * .5f * 255.f), (byte)((normal.y + 1.f) * .5f * 255), 0};
#endif
}
