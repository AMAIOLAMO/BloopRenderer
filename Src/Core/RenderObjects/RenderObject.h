#pragma once

#include "../Types/Type3.h"

namespace Bloop
{
	using namespace CXUtils;

	/// <summary>
	///		an object where could be renderered in scene
	/// </summary>
	class RenderObject
	{
	private:
		Float3 _position;

	public:
		RenderObject();
		RenderObject(const Float3& position);
	};
}


