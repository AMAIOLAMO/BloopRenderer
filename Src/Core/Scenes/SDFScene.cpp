#include "SDFScene.h"

#include <Type2.h>
#include <RayCastInfo.h>

using namespace Bloop;

SDFScene::SDFScene() :
        Scene<SDFRenderObject>(), _maxRayCastIteration( 100 ),
        _maxRayMarchDistance( 120.f ), _minRayMarchDistance( .001f ), _normalEpsilon( .01f )
{ }

SDFScene::SDFScene( const size_t& maxRayCastIteration, const float& maxRayMarchDistance,
                    const float& minRayMarchDistance, const float& normalEpsilon ) :
        Scene(),
        _maxRayCastIteration( maxRayCastIteration ), _maxRayMarchDistance( maxRayMarchDistance ),
        _minRayMarchDistance( minRayMarchDistance ), _normalEpsilon( normalEpsilon )
{ }


float SDFScene::FindClosestDistanceFromPoint( const Float3& point ) const
{
    if ( renderObjects.empty() ) return std::numeric_limits<float>::max();
    //else

    float bestMin = std::numeric_limits<float>::max();

    for ( const auto& renderObject: renderObjects )
    {
        float dist = renderObject->GetDistance( point );
        if ( dist > bestMin ) continue;
        bestMin = dist;
    }

    return bestMin;
}

float SDFScene::FindClosestDistanceFromPoint( const Float3& point, size_t& index ) const
{
    if ( renderObjects.empty() ) return std::numeric_limits<float>::max();
    //else

    float bestMin = std::numeric_limits<float>::max();

    for ( size_t i = 0; i < renderObjects.size(); i++ )
    {
        float dist = renderObjects[i]->GetDistance( point );
        if ( dist > bestMin ) continue;
        bestMin = dist;
        index = i;
    }

    return bestMin;
}

RayCastInfo<SDFRenderObject> SDFScene::RayCast( const Ray& ray ) const
{
    Float3 marchPoint = ray.origin;

    float endDist = 0.f;

    for ( size_t i = 0; i < _maxRayCastIteration; ++i )
    {
        size_t currentIndex;
        float dist = FindClosestDistanceFromPoint( marchPoint, currentIndex );
        endDist += dist;

        //too far
        if ( endDist > _maxRayMarchDistance ) break;

        //marched but didn't find anything useful
        if ( dist > _minRayMarchDistance )
        {
            marchPoint += ray.direction * dist;
            continue;
        }
        //else casted

        return {marchPoint, ray.direction, endDist, renderObjects[currentIndex].get()};
    }

    //else didn't hit anything
    return {ray.direction, endDist};
}

Float3 SDFScene::GetNormal( const Float3& point ) const
{
    float d = FindClosestDistanceFromPoint( point );

    return Float3(
            d - FindClosestDistanceFromPoint( point - Float3( _normalEpsilon, 0, 0 ) ),
            d - FindClosestDistanceFromPoint( point - Float3( 0, _normalEpsilon, 0 ) ),
            d - FindClosestDistanceFromPoint( point - Float3( 0, 0, _normalEpsilon ) )
    ).Normalized();
}





