#ifndef LINEAR_LINKED_LIST_APP_HPP
#define LINEAR_LINKED_LIST_APP_HPP

#include "../Application.hpp"

namespace cld
{
    class LinearLinkedListApp final : public cld::Application
    {
    public:
        void Execute(int argc, char* argv[]) override;
    };
}

#endif // LINEAR_LINKED_LIST_APP_HPP