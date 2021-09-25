#include "Camera.h"

using namespace Bloop;

Camera::Camera( const Float3& position, const Float3& up, const Float3& forward, const float& fov ) :
        position( position ), up( up ), forward( forward ), fov( fov )
{ }

Float4x4 Camera::GetUVToViewLocalMatrix() const
{
    const auto right = up.Cross( forward ); // forward x -up = up x forward

    return {
            right.x, right.y, right.z, 0,
            up.x, up.y, up.z, 0,
            forward.x, forward.y, forward.z, 0, // not negative Forward here, because camera is using negative forward
            0, 0, 0, 1
    };
}
