#include "SceneRenderer.h"

using namespace Bloop;

SceneRenderer::SceneRenderer(const RenderProfile& renderProfile) : _renderProfile(renderProfile) {}

Color8 SceneRenderer::RenderPixel(const Camera& camera, const Scene& scene, const Float2& uv)
{
	return Color8((byte)(uv.x * 255.f), (byte)(uv.y * 255.f), (byte)1);
}
