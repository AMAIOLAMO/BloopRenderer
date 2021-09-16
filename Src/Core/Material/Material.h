#pragma once

#include "../../../Vendor/Plugins/CXUtils/Color/Color8.h"

namespace Bloop
{
	using namespace CXUtils;

	const struct RayCastInfo;

	/// <summary>
	///		A class that stores all the required information for a material
	/// </summary>
	class Material
	{
	public:
		virtual Color8 RenderFragment(const RayCastInfo& rayInfo) const = 0;
	};
}


