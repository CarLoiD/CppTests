#include "Types.hpp"
#include "InlineUtils.hpp"

#include "Application/HelloWorldApp.hpp"
#include "Application/LinearLinkedListApp.hpp"
#include "Application/ThreadAsyncTaskApp.hpp"
#include "Application/Gtk3WindowApp.hpp"
#include "Application/X11OpenGLWindowApp.hpp"

#include <memory>

namespace cld
{
    enum class OperationId : uint16
    {
        HelloWorld,
        LinearLinkedList,
        ThreadAsyncTask,
        Gtk3Window,
        X11OpenGLWindow,
        Quit
    }; const uint16 operationIdLenght = (uint16)OperationId::Quit - (uint16)OperationId::HelloWorld;
}

void PrintInstructions();
cld::OperationId GetOperationId();

int main(int argc, char* argv[])
{
    std::unique_ptr<cld::Application> app;

    const cld::OperationId operationId = GetOperationId();
    switch (operationId) 
    {
        // Hello World Application
        case cld::OperationId::HelloWorld:
            app = std::make_unique<cld::HelloWorldApp>();
        break;

        // Linear Linked List Application
        case cld::OperationId::LinearLinkedList:
            app = std::make_unique<cld::LinearLinkedListApp>();
        break;

        // Thread Async Task Application
        case cld::OperationId::ThreadAsyncTask:
            app = std::make_unique<cld::ThreadAsyncTaskApp>();
        break;

        // Gtkmm3 Window Application
        case cld::OperationId::Gtk3Window:
            app = std::make_unique<cld::Gtk3WindowApp>();
        break;

        // X11 Modern OpenGL Window Application
        case cld::OperationId::X11OpenGLWindow:
            app = std::make_unique<cld::X11OpenGLWindowApp>();
        break;

        // Quit the program
        case cld::OperationId::Quit:
            std::exit(0);
        break;
    }

    // Execute the chosen application
    app.get()->Execute(argc, argv);

    return 0;
}

void PrintInstructions()
{
    cld::ClearConsole();

    std::cout << "##################################\n";
    std::cout << "#           CPP-TESTS            #\n";
    std::cout << "##################################\n\n";

    std::cout << "0) Hello World\n";
    std::cout << "1) Linear Linked List\n";
    std::cout << "2) Thread Async Task\n";
    std::cout << "3) Gtk3 GUI Window\n";
    std::cout << "4) X11 Modern OpenGL Window\n";
    std::cout << "5) Quit\n\n";

    std::cout << "Option: ";
}

cld::OperationId GetOperationId()
{
    int16 option = -1;

    while (option < 0 || option > cld::operationIdLenght) 
    {
        PrintInstructions();
        std::cin >> option;
    }

    cld::ClearConsole();
    return (cld::OperationId) option;
}