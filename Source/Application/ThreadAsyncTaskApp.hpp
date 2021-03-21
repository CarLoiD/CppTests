#ifndef THREAD_ASYNC_TASK_APP_HPP
#define THREAD_ASYNC_TASK_APP_HPP

#include "../Application.hpp"

namespace cld
{
    class ThreadAsyncTaskApp final : public cld::Application
    {
    public:
        void Execute(int argc, char* argv[]) override;
    };
}

#endif // THREAD_ASYNC_TASK_APP_HPP