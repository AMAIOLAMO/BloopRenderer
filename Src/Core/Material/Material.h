#pragma once

#include "../../../Vendor/Plugins/CXUtils/Color/Color8.h"

namespace Bloop
{
	using namespace CXUtils;

	/// <summary>
	///		A class that stores all the required information for a material
	/// </summary>
	class Material
	{
	public:
		virtual Color8 RenderPixel() const = 0;
	};
}


