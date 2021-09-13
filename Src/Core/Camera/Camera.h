#pragma once

#include "../Types/Type3.h"

namespace Bloop
{
	using namespace CXUtils;

	/// <summary>
	///		The view of the world :D
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


