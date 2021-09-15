#pragma once

#include "../Scene.h"
#include "../Camera/Camera.h"
#include "../RenderProfile/RenderProfile.h"
#include "../../../Vendor/Plugins/CXUtils/Color/Color8.h"
#include "../../../Vendor/Plugins/CXUtils/Vectors/Type2.h"

namespace Bloop
{
	/// <summary>
	///		A factory used for renderering a scene
	/// </summary>
	class SceneRenderer
	{
	private:
		const RenderProfile _renderProfile;

	public:
		SceneRenderer(const RenderProfile& renderProfile);

		Color8 RenderPixel(const Camera& camera, const Scene& scene, const Float2& uv);
	};
}


