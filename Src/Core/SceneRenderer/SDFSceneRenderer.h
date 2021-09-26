#pragma once

#include "SceneRenderer.h"

#include <SDFScene.h>
//#include <BMPCubeMap.h>

namespace Bloop
{
    class BMPCubeMap;

    using namespace CXUtils;

    class SDFSceneRenderer : public SceneRenderer<SDFScene>
    {
    private:
        /*const BMPCubeMap& _cubeMap;*/

    public:
        explicit SDFSceneRenderer( const RenderProfile& renderProfile/*, const BMPCubeMap& cubeMap*/ );

        // Inherited via SceneRenderer
        [[nodiscard]] Color8 RenderFragment(
                const Camera& camera, const SDFScene& scene, const Float2& uv ) const override;
    };
}


