#pragma once

#include "Scene.h"
#include <SDFRenderObject.h>

namespace Bloop
{
    class SDFScene : public Scene<SDFRenderObject>
    {
    private:
        const size_t _maxRayCastIteration;
        const float _maxRayMarchDistance;
        const float _minRayMarchDistance;
        const float _normalEpsilon;

    public:
        SDFScene();

        SDFScene( const size_t& maxRayCastIteration, const float& maxRayMarchDistance,
                  const float& minRayMarchDistance, const float& normalEpsilon );

    protected:
        [[nodiscard]] float FindClosestDistanceFromPoint( const Float3& point ) const;

        [[nodiscard]] float FindClosestDistanceFromPoint( const Float3& point, size_t& index ) const;

    public:
        [[nodiscard]] Float3 GetNormal( const Float3& point ) const;

        /// <summary>
        ///		Shoots a ray into the scene and returns whether
        /// </summary>
        [[nodiscard]] RayCastInfo<SDFRenderObject> RayCast( const Ray& ray ) const override;
    };
}


