#pragma once

#include "../Material.h"

namespace Bloop
{
	/// <summary>
	///		A basic material that has a color
	/// </summary>
	class ColorMaterial : public Material
	{
	protected:
		Color8 color;

	public:
		ColorMaterial(const Color8& color);
	};
}


