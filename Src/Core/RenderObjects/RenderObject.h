#pragma once

#include <memory>

#include "../../../Vendor/Plugins/CXUtils/Vectors/Type3.h"
#include "../Material/Material.h"

namespace Bloop
{
	using namespace CXUtils;

	/// <summary>
	///		an object which could be rendered in scene
	/// </summary>
	class RenderObject
	{
	protected:
		Float3 _position;
		Material* _material;

	public:
		RenderObject(const Float3& position, Material* material);
		~RenderObject();

		[[nodiscard]] const Float3& GetPosition() const;
		[[nodiscard]] const Material& GetMaterial() const;
	};
}


