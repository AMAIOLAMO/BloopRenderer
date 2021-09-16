#include "RenderObject.h"

using namespace Bloop;

RenderObject::~RenderObject()
{
	delete _material;
}

const Float3& RenderObject::GetPosition() const
{
	return _position;
}

const Material& RenderObject::GetMaterial() const
{
	return *_material;
}

RenderObject::RenderObject(const Float3& position, Material* material) : _position(position), _material(material) {  }
