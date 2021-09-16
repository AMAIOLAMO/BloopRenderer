#include "RenderObject.h"

using namespace Bloop;

RenderObject::~RenderObject()
{
	delete _material;
}

RenderObject::RenderObject(const Float3& position, Material* material) : _position(position), _material(material) {  }
