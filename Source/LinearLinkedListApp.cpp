#include "LinearLinkedListApp.hpp"

#include "InlineUtils.hpp"
#include "LinearLinkedList.hpp"

void cld::LinearLinkedListApp::Execute(int argc, char* argv[])
{
    std::cout << "-- Linear Linked List --\n\n";

    cld::LinearLinkedList<uint32> list;
    list.Insert(25);
    list.Insert(100230);
    list.Insert(98);
    list.Insert(0);
    list.Insert(32);
    list.Insert(69);

    std::cout << "Original list: "; list.PrintAll(' ');
    std::cout << "List Size: " << list.Size() << "\n\n";

    std::cout << "Deleting second element...\n\n";
    list.Delete(1);

    std::cout << "Modified list: "; list.PrintAll(' ');
    std::cout << "List Size: " << list.Size() << "\n\n";

    std::cout << "Fourth element: " << list[3] << '\n';
    
    list.Set(3, 69);
    std::cout << "Modified fourth element (lmao): " << list[3] << "\n\n";

    std::cout << "Actual list: "; list.PrintAll(' ');
    std::cout << "Clearing the list...\n\n";

    list.Clear();
    std::cout << "Actual list: "; list.PrintAll(' ');

    HoldNextInput();
}