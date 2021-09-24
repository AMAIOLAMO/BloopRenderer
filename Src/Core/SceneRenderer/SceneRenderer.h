#pragma once

#include <utility>

#include <Camera.h>
#include <RenderProfile.h>
#include <Color8.h>
#include <Type2.h>

namespace Bloop
{
    /// <summary>
    ///		A factory used for rendering a scene
    /// </summary>
    template<typename T>
    class SceneRenderer
    {
    protected:
        const RenderProfile renderProfile;

    protected:
        explicit SceneRenderer( RenderProfile renderProfile ) : renderProfile( std::move( renderProfile ) )
        { }

        virtual Color8 RenderFragment( const Camera& camera, const T& scene, const Float2& uv ) const = 0;

    public:
        /// <summary>
        ///     Renders an image using the given ONE DIMENSIONAL ColorBuffer
        /// </summary>
        virtual void RenderImage( const Camera& camera, const T& scene,
                                  const UInt2& resolution, Color8* const& colorBuffer ) const
        {
            for ( size_t x = 0; x < resolution.x; ++x )
            {
                for ( size_t y = 0; y < resolution.y; ++y )
                {
                    colorBuffer[x + y * resolution.x] =
                            RenderFragment( camera, scene, Float2(
                                                    (float) x / static_cast<float>(resolution.x),
                                                    (float) y / static_cast<float>(resolution.y)
                                            )
                            );
                }
            }
        }
    };
}


