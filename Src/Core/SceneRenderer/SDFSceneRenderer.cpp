#include "SDFSceneRenderer.h"

#include <RayCastInfo.h>
#include <SDFMaterial.h>

using namespace Bloop;

SDFSceneRenderer::SDFSceneRenderer( const RenderProfile& renderProfile ) : SceneRenderer( renderProfile )
{ }

Color8 SDFSceneRenderer::RenderFragment( const Camera& camera, const SDFScene& scene, const Float2& uv ) const
{
    const float aspectRatio = (float) renderProfile.Dimension.x / (float) renderProfile.Dimension.y;

    const Float4x4 uvToCamLocalMatrix = camera.GetUVToViewLocalMatrix();

    const Float3 newUV = Float3(
            (uv.x - .5f) * 2.f * aspectRatio * camera.fov,
            (uv.y - .5f) * 2.f * camera.fov,
            100.f ).Normalized();

    /*const Float3 newViewDir = Float3(
            (uv.x - .5f) * 2.f * aspectRatio * camera.fov,
            (uv.y - .5f) * 2.f * camera.fov,
            1.f ).Normalized();*/

    const Float3 newViewDir = uvToCamLocalMatrix.TransformDirection( newUV );

    const auto info = scene.RayCast( Ray( camera.position, newViewDir ) );

    if ( info.DidntHit() ) return {0, 0, 0};
    //else hit

#if 1
    return info.renderObject->GetMaterial().RenderFragment( info, scene );
#else //DEBUG
    const auto normal = scene.GetNormal(info.endPoint);

    return {(byte)((normal.x + 1.f) * .5f * 255.f), (byte)((normal.y + 1.f) * .5f * 255), 0};
#endif
}
