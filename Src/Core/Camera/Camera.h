#pragma once

#include <Type3.h>
#include <Type2.h>
#include <Matrix4x4.h>

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
		Float3 forward;
        Float3 up;
        float fov;

	public:
		Camera(const Float3& position, const Float3& up, const Float3& forward, const float& fov = 20.f);

    public:
        [[nodiscard]] Float4x4 GetUVToViewLocalMatrix() const;
	};
}


