
namespace cld
{
    template <typename T>
    LinearLinkedList<T>::LinearLinkedList(const uint32 size)
        : mHeadPtr(nullptr)
        , mLenght(size)
    {
        for (uint32 index = 0; index < mLenght; ++index) {
            Insert(static_cast<T>(0));
        }
    }

    template <typename T>
    LinearLinkedList<T>::LinearLinkedList(const uint32 size, const T& data)
        : mHeadPtr(nullptr)
        , mLenght(size)
    {
        for (uint32 index = 0; index < mLenght; ++index) {
            Insert(data);
        }
    }

    template <typename T>
    LinearLinkedList<T>::~LinearLinkedList()
    {
        Clear();
    }

    template <typename T>
    void LinearLinkedList<T>::Insert(const T& data)
    {
        if (mLenght == 0) 
        {
            mHeadPtr = new Node();
            mHeadPtr->Data = data;
            mHeadPtr->Next = nullptr;

            ++mLenght;
            return;
        }

        // Iterate to the last element
        Node* last = mHeadPtr;
        while (last->Next != nullptr) {
            last = last->Next;
        }

        Node* newLast = new Node();
        newLast->Data = data;
        newLast->Next = nullptr;

        last->Next = newLast;
        ++mLenght;
    }

    template <typename T>
    void LinearLinkedList<T>::Delete(const uint32 index)
    {
        Assert(index >= 0 && index < mLenght, "ERROR: List index out of bounds!");

        Node* tmpHead = mHeadPtr;

        if (index == 0) 
        {
            if (mLenght > 1) {
                mHeadPtr = mHeadPtr->Next;
                tmpHead->Next = nullptr;
            }

            delete tmpHead;
            --mLenght;

            return;
        }

        uint32 iterator = 0;
        while (iterator < index - 1) {
            tmpHead = tmpHead->Next;
            ++iterator;
        }

        Node* nextAfterDeleted = tmpHead->Next->Next;
        
        delete tmpHead->Next; // Delete the one in the "middle"
        --mLenght;

        tmpHead->Next = nextAfterDeleted;
    }
    
    template <typename T>
    void LinearLinkedList<T>::PrintAll(const char separator) const
    {
        // Skip if the list is empty
        if (mLenght < 1) return;

        Node* current = mHeadPtr;

        while (current->Next != nullptr) {
            std::cout << current->Data << separator;
            current = current->Next;
        }

        // Print the last one
        std::cout << current->Data;
    }

    template <typename T>
    void LinearLinkedList<T>::Set(const uint32 index, const T& data)
    {
        Assert(index >= 0 && index < mLenght, "ERROR: List index out of bounds!");

        Node* current = mHeadPtr;
        uint32 iterator = 0;

        while (iterator < index) {
            current = current->Next;
            ++iterator;
        }

        current->Data = data;
    }

    template <typename T>
    void LinearLinkedList<T>::Clear()
    {
        if (mLenght < 1) return;

        Node* current = mHeadPtr;
        Node* next = nullptr;

        while (current != nullptr) 
        {
            next = current->Next;
            delete current;

            current = next;
        }

        mHeadPtr = nullptr;
        mLenght = 0;
    }

    template <typename T>
    uint32 LinearLinkedList<T>::Size() const
    {
        return mLenght;
    }

    template <typename T>
    const T& LinearLinkedList<T>::operator[](const uint32 index)
    {
        Assert(index >= 0 && index < mLenght, "ERROR: List index out of bounds!");

        Node* current = mHeadPtr;
        uint32 iterator = 0;

        while (iterator < index) {
            current = current->Next;
            ++iterator;
        }

        return current->Data;
    }     
}
