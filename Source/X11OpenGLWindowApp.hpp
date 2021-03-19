#ifndef X11_OPENGL_WINDOW_APP_HPP
#define X11_OPENGL_WINDOW_APP_HPP

#include "Application.hpp"

namespace cld
{
    class X11OpenGLWindowApp final : public cld::Application
    {
    public:
        void Execute(int argc, char* argv[]) override;
    };
}

#endif // X11_OPENGL_WINDOW_APP_HPP