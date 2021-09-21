#pragma once

#include <memory>

#include <Type3.h>

namespace Bloop {
    using namespace CXUtils;

    /// <summary>
    ///		an object which could be rendered in scene
    /// </summary>
    template<typename TMaterial>
    class RenderObject {
    protected:
        Float3 _position;
        TMaterial *_material;

    public:
        RenderObject(const Float3 &position, TMaterial *material) : _position(position), _material(material) {}

        ~RenderObject() { delete _material; }

        [[nodiscard]] const Float3 &GetPosition() const { return _position; }

        [[nodiscard]] const TMaterial &GetMaterial() const { return *_material; }
    };
}