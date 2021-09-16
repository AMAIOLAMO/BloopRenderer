#pragma once

#include "SceneRenderer.h"
#include "../Scenes/SDFScene.h"

namespace Bloop
{
	using namespace CXUtils;

	class SDFSceneRenderer : public SceneRenderer<SDFScene>
	{
	public:
		SDFSceneRenderer(const RenderProfile& renderProfile);

		// Inherited via SceneRenderer
		virtual Color8 RenderFragment(const Camera& camera, const SDFScene& scene, const Float2& uv) const;
	};
}


