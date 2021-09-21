#pragma once

#include <RenderObject.h>

namespace Bloop
{
    class SDFMaterial;

    /// <summary>
    ///		An SDF (Signed distance function) driven render object
    /// </summary>
    class SDFRenderObject : public RenderObject<SDFMaterial>
    {
    public:
        SDFRenderObject( const Float3& position, SDFMaterial* material );

    public:
        [[nodiscard]] virtual float GetDistance( const Float3& point ) const = 0;
    };
}