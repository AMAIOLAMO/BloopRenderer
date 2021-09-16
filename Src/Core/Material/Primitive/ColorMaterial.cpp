#include "ColorMaterial.h"

using namespace Bloop;

ColorMaterial::ColorMaterial(const Color8& color) : _color(color) {}

Color8 ColorMaterial::RenderPixel(const Scene& scene) const { return _color; }
