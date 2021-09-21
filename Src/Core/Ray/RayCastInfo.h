#pragma once

#include "../../../Vendor/Plugins/CXUtils/Vectors/Type3.h"

namespace Bloop
{
	using namespace CXUtils;

	class RenderObject;

	/// <summary>
	///		The info returned after ray casting
	/// </summary>
	const struct RayCastInfo
	{
	public:
		const Float3        endPoint;
		const Float3		direction;
		const float         distance;
		const RenderObject* renderObject;

	public:
		RayCastInfo(const Float3& direction, const float& distance);
		RayCastInfo(const Float3& endPoint, const Float3& direction, const float& distance, const RenderObject* renderObject);

	public:
		bool DidntHit() const;
	};
}


