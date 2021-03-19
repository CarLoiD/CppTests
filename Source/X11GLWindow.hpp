#ifndef X11_GL_WINDOW_HPP
#define X11_GL_WINDOW_HPP

#include "Types.hpp"
#include "InlineUtils.hpp"

#include <X11/Xlib.h>

#include <epoxy/gl.h>
#include <epoxy/glx.h>

namespace cld
{
    class X11GLWindow final
    {
    public:
        X11GLWindow(const uint32 width, const uint32 height, const char* caption);
        ~X11GLWindow();

        void ProcessEvents();
        void Move(const int32 x, const int32 y);
        void Show() const;
        void Clear(const uint32 dwColor);
        void SwapBuffers();

    private:
        Display* X11Display;
        Screen* X11Screen;
        Window X11Window;
        XEvent EventHandler;

        GLXContext Context;
    };
}


#endif // X11_GL_WINDOW_HPP