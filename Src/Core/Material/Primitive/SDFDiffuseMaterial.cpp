#include "SDFDiffuseMaterial.h"

#include <RayCastInfo.h>
#include <SDFScene.h>

using namespace Bloop;

SDFDiffuseMaterial::SDFDiffuseMaterial( const Color8& color ) : SDFColorMaterial{color}
{ }

const Float3 fakeLightPosition( Float3{-3, 1, 0} );

Color8 SDFDiffuseMaterial::RenderFragment( const RayCastInfo<SDFRenderObject>& rayInfo, const SDFScene& scene ) const
{
    Float3 fakeLightDirection = (fakeLightPosition - rayInfo.renderObject->GetPosition()).Normalized();

    float diffuse = std::fmax( fakeLightDirection.Dot( scene.GetNormal( rayInfo.endPoint ) ), .1f );

    byte r = (byte) ((float) color.r * diffuse),
            g = (byte) ((float) color.g * diffuse),
            b = (byte) ((float) color.b * diffuse);

    return {r, g, b};
}