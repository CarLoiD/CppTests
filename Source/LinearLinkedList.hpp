#ifndef LINEAR_LINKED_LIST_HPP
#define LINEAR_LINKED_LIST_HPP

#include "Types.hpp"
#include "InlineUtils.hpp"

namespace cld
{
    template <typename Type>
    class LinearLinkedList final
    {
    private:
        struct Node 
        {
            Type Data;
            Node* Next;
        };
        
    public:
        LinearLinkedList();
        LinearLinkedList(const uint32 size);
        LinearLinkedList(const uint32 size, const Type& data);

        ~LinearLinkedList();

        void Insert(const Type& data);
        void Delete(const uint32 index);
        void PrintAll(const char separator) const;
        void Set(const uint32 index, const Type& data);
        void Clear();
        uint32 Size() const;

        const Type& operator[](const uint32 index);

    private:
        Node* HeadPtr;
        uint32 Lenght;
    };
}

#include "LinearLinkedList.inl"

#endif // LINEAR_LINKED_LIST_HPP