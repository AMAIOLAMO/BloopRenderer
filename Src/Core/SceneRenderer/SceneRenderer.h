#pragma once

#include "../Camera/Camera.h"
#include "../RenderProfile/RenderProfile.h"
#include "../../../Vendor/Plugins/CXUtils/Color/Color8.h"
#include "../../../Vendor/Plugins/CXUtils/Vectors/Type2.h"

namespace Bloop
{
	/// <summary>
	///		A factory used for renderering a scene
	/// </summary>
	template<typename T>
	class SceneRenderer
	{
	protected:
		const RenderProfile renderProfile;

	protected:
		SceneRenderer(const RenderProfile& renderProfile) : renderProfile(renderProfile) {}

		virtual Color8 RenderFragment(const Camera& camera, const T& scene, const Float2& uv) const = 0;
	};
}


