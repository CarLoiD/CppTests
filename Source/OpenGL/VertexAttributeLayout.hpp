#ifndef VERTEX_ATTRIBUTE_LAYOUT_HPP
#define VERTEX_ATTRIBUTE_LAYOUT_HPP

#include "../Types.hpp"
#include "../InlineUtils.hpp"

namespace cld
{
    enum class AttributeType
    {
        Float,
        Int,
        Uint,
        Vec2Float,
        Vec3Float,
        Vec4Float,
        Vec2Int,
        Vec3Int,
        Vec4Int,
        Vec2Uint,
        Vec3Uint,
        Vec4Uint
    };

    struct AttributeElement
    {
        std::string Semantic;
        uint32 Index;
        AttributeType Type;
    };
}

#endif // VERTEX_ATTRIBUTE_LAYOUT_HPP