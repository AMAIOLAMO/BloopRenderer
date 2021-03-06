#pragma once

#include <Color8.h>
#include <Material.h>
#include <SDFRenderObject.h>

namespace Bloop
{
    template<typename TRenderObject>
    struct RayCastInfo;

    class SDFScene;

    /// <summary>
    ///     A Material that is based on SDF
    /// </summary>
	class SDFMaterial : public Material
	{
    public:
        [[nodiscard]] virtual Color8 RenderFragment(const RayCastInfo<SDFRenderObject>& rayInfo, const SDFScene& scene) const = 0;
	};
}