#pragma once

#include "SceneRenderer.h"
#include <SDFScene.h>

namespace Bloop
{
	using namespace CXUtils;

	class SDFSceneRenderer : public SceneRenderer<SDFScene>
	{
	public:
		explicit SDFSceneRenderer(const RenderProfile& renderProfile);

		// Inherited via SceneRenderer
		[[nodiscard]] Color8 RenderFragment(const Camera& camera, const SDFScene& scene, const Float2& uv) const override;
	};
}


