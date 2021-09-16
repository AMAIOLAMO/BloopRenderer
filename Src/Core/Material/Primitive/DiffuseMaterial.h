#pragma once

#include "ColorMaterial.h"

namespace Bloop
{
	/// <summary>
	///		Simple diffuse lighting
	/// </summary>
	class DiffuseMaterial : public ColorMaterial
	{
	public:
		DiffuseMaterial(const Color8& color);

	public:
		//virtual Color8 RenderFragment(const RayCastInfo& rayInfo) const override;
	};
}


