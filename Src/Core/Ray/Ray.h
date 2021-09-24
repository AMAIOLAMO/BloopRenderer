#pragma once
#include <Type3.h>

namespace Bloop
{
	using namespace CXUtils;

	/// <summary>
	///		A struct wrapping over a simple ray
	/// </summary>
	struct Ray
	{
	public:
		const Float3 origin;
		const Float3 direction;

	public:
		Ray(const Float3& origin, const Float3& direction);
	};
}


