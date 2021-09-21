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
		SDFDiffuseMaterial(const Color8& color);

	public:
		virtual Color8 RenderFragment(const RayCastInfo& rayInfo) const override;
	};
}