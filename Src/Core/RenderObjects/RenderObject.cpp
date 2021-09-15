#include "RenderObject.h"

using namespace Bloop;

RenderObject::RenderObject() : _position(0.f, 0.f, 0.f), _material() {  }
RenderObject::RenderObject(const Float3& position, const Material& material) : _position(position), _material(material) {  }
