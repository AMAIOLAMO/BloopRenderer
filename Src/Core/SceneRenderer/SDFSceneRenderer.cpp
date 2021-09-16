#include "SDFSceneRenderer.h"

using namespace Bloop;

SDFSceneRenderer::SDFSceneRenderer(const RenderProfile& renderProfile) : SceneRenderer(renderProfile) {}

Color8 SDFSceneRenderer::RenderPixel(const Camera& camera, const SDFScene& scene, const Float2& uv) const
{
	const float dimensionRate = (float)renderProfile.Dimension.y / renderProfile.Dimension.x;

	const Float3 newViewDir = Float3(
		camera.viewDirection.x + (uv.x - .5f) * 2.f,
		camera.viewDirection.y + (uv.y - .5f) * 2.f * dimensionRate,
		1.f)
		.Normalized();

	const auto info = scene.RayCast(Ray(camera.position, newViewDir));

	if (info.DidntHit()) return Color8(0, 0, 0);
	//else hit

	return info.renderObject->GetMaterial().RenderPixel();
}
