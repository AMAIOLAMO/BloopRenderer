#pragma once

#include <Type3.h>
#include <Type2.h>

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

    public:
        /*[[nodiscard]] Float3 RayFromUV(const Float2& uv, const UInt2& resolution) const;*/
	};
}


