#include "HelloWorldApp.hpp"

#include "../Types.hpp"
#include "../InlineUtils.hpp"

void cld::HelloWorldApp::Execute(int argc, char* argv[])
{
    std::cout << "Hello World from CppTests!\n";

    cld::HoldNextInput();
    cld::ClearConsole();
}