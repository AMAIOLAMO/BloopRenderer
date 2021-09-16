#include "DiffuseMaterial.h"

using namespace Bloop;

DiffuseMaterial::DiffuseMaterial(const Color8& color) : ColorMaterial(color) {}

const Float3 _fakeLightPosition(0, 1, 1);

//Color8 DiffuseMaterial::RenderFragment(const RayCastInfo& rayInfo) const
//{
//	const Float3 lightDirection = (rayInfo.endPoint - _fakeLightPosition).Normalized();
//
//	float diffuse = std::max(lightDirection.Dot(rayInfo.direction), 0.f);
//
//	float r = color.r / 255.f * diffuse,
//		g = color.g / 255.f * diffuse,
//		b = color.b / 255.f * diffuse;
//
//	return Color8((byte)(r * 255.f), (byte)(g * 255.f), (byte)(b * 255.f));
//}