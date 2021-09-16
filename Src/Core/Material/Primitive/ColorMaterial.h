#pragma once

#include "../Material.h"

namespace Bloop
{
	/// <summary>
	///		A basic material that is plain
	/// </summary>
	class ColorMaterial : public Material
	{
	protected:
		Color8 _color;

	public:
		ColorMaterial(const Color8& color);

	public:
		virtual Color8 RenderPixel(const Scene& scene) const override;
	};
}


