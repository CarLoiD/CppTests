#include "X11GLWindow.hpp"

cld::X11GLWindow::X11GLWindow(const uint32 width, const uint32 height, const char* caption)
    : X11Display(nullptr)
    , X11Screen(nullptr)
{
    X11Display = XOpenDisplay(nullptr);
    Assert(X11Display != nullptr, "ERROR: Failed to open X11 display!");

    X11Screen = DefaultScreenOfDisplay(X11Display);
    const int32 screenId = DefaultScreen(X11Display);

    X11Window = XCreateSimpleWindow(X11Display, RootWindowOfScreen(X11Screen), 0, 0, width, height, 1,
                                    BlackPixel(X11Display, screenId), WhitePixel(X11Display, screenId));

    // Set the window title caption
    XStoreName(X11Display, X11Window, caption);

    GLint glxAttribs[] = {
        GLX_RGBA,
        GLX_DOUBLEBUFFER,
        GLX_DEPTH_SIZE,     24,
        GLX_STENCIL_SIZE,   8,
        GLX_RED_SIZE,       8,
        GLX_GREEN_SIZE,     8,
        GLX_BLUE_SIZE,      8,
        GLX_SAMPLE_BUFFERS, 0,
        GLX_SAMPLES,        0,
        None
    };

    XVisualInfo* visual = glXChooseVisual(X11Display, screenId, glxAttribs);
    Assert(visual != nullptr, "ERROR: Failed to create visual info to the X11 display!");

    // Make context current
    Context = glXCreateContext(X11Display, visual, nullptr, GL_TRUE);
    glXMakeCurrent(X11Display, X11Window, Context);
}

cld::X11GLWindow::~X11GLWindow()
{
    glXDestroyContext(X11Display, Context);

    XDestroyWindow(X11Display, X11Window);
    XFree(X11Screen);
    XCloseDisplay(X11Display);
}

void cld::X11GLWindow::ProcessEvents()
{
    // Check for drawing/input events
    XCheckWindowEvent(X11Display, X11Window, ExposureMask | ButtonPressMask, &EventHandler);
}

void cld::X11GLWindow::Move(const int32 x, const int32 y)
{
    XMoveWindow(X11Display, X11Window, x, y);
}

void cld::X11GLWindow::Show() const
{
    XClearWindow(X11Display, X11Window);
    XMapRaised(X11Display, X11Window);
}

void cld::X11GLWindow::Clear(const uint32 dwColor)
{
    float r, g, b, a;
    
    DwordToColorNormalized(dwColor, r, g, b, a);
    glClearColor(r, g, b, a);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glClearDepth(1.0f);
}

void cld::X11GLWindow::SwapBuffers()
{
    glXSwapBuffers(X11Display, X11Window);
}