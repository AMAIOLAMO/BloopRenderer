#pragma once

#include "../RenderObjects/RenderObject.h"
#include "../../../Vendor/Plugins/CXUtils/Vectors/Type3.h"

namespace Bloop
{
	using namespace CXUtils;

	/// <summary>
	///		The info returned after raycasting
	/// </summary>
	struct RayCastInfo
	{
	public:
		const Float3 endPoint;
		const Float3 direction;
		const float distance;
		const RenderObject* renderObject;

	public:
		RayCastInfo(const Float3& endPoint, const Float3& direction, const float& distance, const RenderObject* renderObject);
	};
}


