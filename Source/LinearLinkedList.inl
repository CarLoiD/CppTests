
namespace cld
{
    template <typename Type>
    LinearLinkedList<Type>::LinearLinkedList()
        : HeadPtr(nullptr)
        , Lenght(0)
    {}

    template <typename Type>
    LinearLinkedList<Type>::LinearLinkedList(const uint32 size)
        : HeadPtr(nullptr)
        , Lenght(size)
    {
        for (uint32 index = 0; index < Lenght; ++index) {
            Insert((Type)0);
        }
    }

    template <typename Type>
    LinearLinkedList<Type>::LinearLinkedList(const uint32 size, const Type& data)
        : HeadPtr(nullptr)
        , Lenght(size)
    {
        for (uint32 index = 0; index < Lenght; ++index) {
            Insert(data);
        }
    }

    template <typename Type>
    LinearLinkedList<Type>::~LinearLinkedList()
    {
        Clear();
    }

    template <typename Type>
    void LinearLinkedList<Type>::Insert(const Type& data)
    {
        if (Lenght == 0) 
        {
            HeadPtr = new Node();
            HeadPtr->Data = data;
            HeadPtr->Next = nullptr;

            ++Lenght;
            return;
        }

        // Iterate to the last element
        Node* last = HeadPtr;
        while (last->Next != nullptr) {
            last = last->Next;
        }

        Node* newLast = new Node();
        newLast->Data = data;
        newLast->Next = nullptr;

        last->Next = newLast;
        ++Lenght;
    }

    template <typename Type>
    void LinearLinkedList<Type>::Delete(const uint32 index)
    {
        Assert(index >= 0 && index < Lenght, "ERROR: List index out of bounds!");

        Node* tmpHead = HeadPtr;

        if (index == 0) 
        {
            if (Lenght > 1) {
                HeadPtr = HeadPtr->Next;
                tmpHead->Next = nullptr;
            }

            delete tmpHead;
            --Lenght;

            return;
        }

        uint32 iterator = 0;
        while (iterator < index - 1) {
            tmpHead = tmpHead->Next;
            ++iterator;
        }

        Node* nextAfterDeleted = tmpHead->Next->Next;
        
        delete tmpHead->Next; // Delete the one in the "middle"
        --Lenght;

        tmpHead->Next = nextAfterDeleted;
    }
    
    template <typename Type>
    void LinearLinkedList<Type>::PrintAll(const char separator) const
    {
        // Skip if the list is empty
        if (Lenght < 1) return;

        Node* current = HeadPtr;

        while (current->Next != nullptr) {
            std::cout << current->Data << separator;
            current = current->Next;
        }

        // Print the last one
        std::cout << current->Data;
    }

    template <typename Type>
    void LinearLinkedList<Type>::Set(const uint32 index, const Type& data)
    {
        Assert(index >= 0 && index < Lenght, "ERROR: List index out of bounds!");

        Node* current = HeadPtr;
        uint32 iterator = 0;

        while (iterator < index) {
            current = current->Next;
            ++iterator;
        }

        current->Data = data;
    }

    template <typename Type>
    void LinearLinkedList<Type>::Clear()
    {
        if (Lenght < 1) return;

        Node* current = HeadPtr;
        Node* next = nullptr;

        while (current != nullptr) 
        {
            next = current->Next;
            delete current;

            current = next;
        }

        HeadPtr = nullptr;
        Lenght = 0;
    }

    template <typename Type>
    uint32 LinearLinkedList<Type>::Size() const
    {
        return Lenght;
    }

    template <typename Type>
    const Type& LinearLinkedList<Type>::operator[](const uint32 index)
    {
        Assert(index >= 0 && index < Lenght, "ERROR: List index out of bounds!");

        Node* current = HeadPtr;
        uint32 iterator = 0;

        while (iterator < index) {
            current = current->Next;
            ++iterator;
        }

        return current->Data;
    }     
}
