#pragma once

#include "../../../Vendor/Plugins/CXUtils/Vectors/Type3.h"

namespace Bloop
{
	using namespace CXUtils;

	/// <summary>
	///		The object used to render
	/// </summary>
	class Camera
	{
	public:
		Float3 position;
		Float3 viewDirection;

	public:
		Camera(const Float3& position, const Float3& viewDirection);
	};
}


