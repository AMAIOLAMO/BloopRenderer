#pragma once

#include "SDFColorMaterial.h"

namespace Bloop
{
	/// <summary>
	///		Simple diffuse lighting
	/// </summary>
	class SDFDiffuseMaterial : public SDFColorMaterial
	{
	public:
		explicit SDFDiffuseMaterial(const Color8& color);

	public:
		[[nodiscard]] Color8 RenderFragment(const RayCastInfo<SDFRenderObject>& rayInfo, const SDFScene& scene) const override;
	};
}