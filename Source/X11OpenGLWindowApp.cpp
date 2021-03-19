#include "X11OpenGLWindowApp.hpp"

#include "Types.hpp"
#include "InlineUtils.hpp"
#include "X11GLWindow.hpp"

constexpr const uint32 g_width  = 1280;
constexpr const uint32 g_height = 720;

void cld::X11OpenGLWindowApp::Execute(int argc, char* argv[])
{
    cld::X11GLWindow window(g_width, g_height, "CppTests - X11OpenGLWindowApp");
    window.Show();
    window.Move(300, 150);

    while (true)
    {
        window.ProcessEvents();

        window.Clear(0x2D2D2DFF);
        window.SwapBuffers();
    }
}