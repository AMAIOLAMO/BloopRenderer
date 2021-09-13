#include "RenderObject.h"

using namespace Bloop;

RenderObject::RenderObject() : _position(0.f, 0.f, 0.f) {  }
RenderObject::RenderObject(const Float3& position) : _position(position) {  }
