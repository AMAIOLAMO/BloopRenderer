#pragma once

#include "../RenderObjects/RenderObject.h"
#include "../../../Vendor/Plugins/CXUtils/Vectors/Type3.h"

namespace Bloop
{
	using namespace CXUtils;

	/// <summary>
	///		The info returned after raycasting
	/// </summary>
	const struct RayCastInfo
	{
	public:
		const Float3        endPoint;
		const float         distance;
		const RenderObject* renderObject;

	public:
		RayCastInfo(const float& distance);
		RayCastInfo(const Float3& endPoint, const float& distance, const RenderObject* renderObject);

	public:
		bool DidntHit() const;
	};
}


