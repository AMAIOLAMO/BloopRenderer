#pragma once

#include "../RenderProfile/RenderProfile.h"

namespace Bloop
{
	/// <summary>
	///		A factory used for renderering a scene
	/// </summary>
	class SceneRenderer
	{
	private:
		const RenderProfile& _renderProfile;

	public:
		SceneRenderer(const RenderProfile& renderProfile);
	};
}


