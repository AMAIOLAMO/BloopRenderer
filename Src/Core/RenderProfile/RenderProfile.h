#pragma once

#include "../../../Vendor/Plugins/CXUtils/Vectors/Type2.h"

namespace Bloop
{
	using namespace CXUtils;

	/// <summary>
	///		Profile settings for rendering using SceneRenderer
	/// </summary>
	struct RenderProfile
	{
	public:
		const UInt2 Dimension;

	public:
		RenderProfile(const UInt2& dimension);
	};
}


