#pragma once

#include "ColorMaterial.h"

namespace Bloop
{
	/// <summary>
	///		Same as ColorMaterial, but is usable for rendering
	/// </summary>
	class PlainMaterial : public ColorMaterial
	{
	public:
		PlainMaterial(const Color8& color);

	public:
		virtual Color8 RenderFragment() const override;
	};
}


