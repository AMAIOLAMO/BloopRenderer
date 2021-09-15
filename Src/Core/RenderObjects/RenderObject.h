#pragma once

#include "../../../Vendor/Plugins/CXUtils/Vectors/Type3.h"
#include "../Material/Material.h"

namespace Bloop
{
	using namespace CXUtils;

	/// <summary>
	///		an object which could be renderered in scene
	/// </summary>
	class RenderObject
	{
	protected:
		Float3 _position;
		Material _material;

	public:
		RenderObject();
		RenderObject(const Float3& position, const Material& material);
	};
}


