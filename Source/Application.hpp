#ifndef APPLICATION_HPP
#define APPLICATION_HPP

namespace cld
{
    class Application
    {
    public:
        virtual void Execute(int argc, char* argv[]) = 0;
    };
}

#endif // APPLICATION_HPP