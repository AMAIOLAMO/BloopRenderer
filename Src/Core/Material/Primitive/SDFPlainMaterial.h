#pragma once

#include "SDFColorMaterial.h"

namespace Bloop
{
	/// <summary>
	///		Same as ColorMaterial, but is usable for rendering
	/// </summary>
	class SDFPlainMaterial : public SDFColorMaterial
	{
	public:
		explicit SDFPlainMaterial(const Color8& color);

	public:
		[[nodiscard]] Color8 RenderFragment(const RayCastInfo& rayInfo) const override;
	};
}
