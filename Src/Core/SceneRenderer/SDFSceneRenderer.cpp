#include "SDFSceneRenderer.h"

using namespace Bloop;

SDFSceneRenderer::SDFSceneRenderer(const RenderProfile& renderProfile) : SceneRenderer(renderProfile) {}

Color8 SDFSceneRenderer::RenderPixel(const Camera& camera, const SDFScene& scene, const Float2& uv) const
{
	const float dimensionRate = (float)renderProfile.Dimension.x / renderProfile.Dimension.y;

	const Float3 newViewDir = Float3(
		camera.viewDirection.x + (uv.y - .5f) * 2.f * 2.f,
		camera.viewDirection.y + (uv.x - .5f) * 2.f * 2.f * dimensionRate,
		camera.viewDirection.z)
		.Normalized();

	const auto info = scene.RayCast(Ray(camera.position, newViewDir));

	if (info.renderObject == nullptr) return Color8(0, 0, 0);
	//else hit

	/*float dist = std::min(1.f - info.distance / SDFScene::MAX_RAYCAST_INTERATION, 1.f);

	byte color = (byte)(dist * 255.f);*/

	return Color8(255, 255, 255);
}
