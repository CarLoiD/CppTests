#ifndef LINEAR_LINKED_LIST_HPP
#define LINEAR_LINKED_LIST_HPP

#include "Types.hpp"
#include "InlineUtils.hpp"

namespace cld
{
    template <typename T>
    class LinearLinkedList final
    {
    private:
        struct Node 
        {
            T Data;
            Node* Next;
        };
        
    public:
        LinearLinkedList() = default;
        LinearLinkedList(const uint32 size);
        LinearLinkedList(const uint32 size, const T& data);

        ~LinearLinkedList();

        void Insert(const T& data);
        void Delete(const uint32 index);
        void PrintAll(const char separator) const;
        void Set(const uint32 index, const T& data);
        void Clear();
        uint32 Size() const;

        const T& operator[](const uint32 index);

    private:
        Node* mHeadPtr;
        uint32 mLenght;
    };
}

#include "LinearLinkedList.inl"

#endif // LINEAR_LINKED_LIST_HPP