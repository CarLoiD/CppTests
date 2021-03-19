#ifndef HELLO_WORLD_APP_HPP
#define HELLO_WORLD_APP_HPP

#include "Application.hpp"

namespace cld
{
    class HelloWorldApp final : public cld::Application
    {
    public:
        void Execute(int argc, char* argv[]) override;
    };
}

#endif // HELLO_WORLD_APP_HPP