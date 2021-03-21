#include "X11OpenGLWindowApp.hpp"

#include "../Types.hpp"
#include "../InlineUtils.hpp"
#include "../X11GLWindow.hpp"

#include "../OpenGL/Shader.hpp"

constexpr const uint32 g_width  = 1280;
constexpr const uint32 g_height = 720;

void cld::X11OpenGLWindowApp::Execute(int argc, char* argv[])
{
    cld::X11GLWindow window(g_width, g_height, "CppTests - X11OpenGLWindowApp");
    window.Show();
    window.Move(300, 150);
    
    // Make sure we're running at least a core profile GL3.0 context
    Assert(epoxy_gl_version() >= 30, "ERROR: GL_VERSION < 3.0!");

    cld::Shader simpleShader;
    simpleShader.CompileShaderFromFile("Source/Shaders/VertexShader.vert", "Source/Shaders/FragmentShader.frag");
    simpleShader.Bind();

    while (true)
    {
        window.ProcessEvents();

        window.Clear(0x2D2D2DFF);
        window.SwapBuffers();
    }

    ClearConsole();
}