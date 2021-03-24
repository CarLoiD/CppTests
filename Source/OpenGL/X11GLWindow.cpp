#include "X11GLWindow.hpp"

cld::X11GLWindow::X11GLWindow(const uint32 width, const uint32 height, const char* caption)
    : mDisplay(nullptr)
    , mScreen(nullptr)
{
    mDisplay = XOpenDisplay(nullptr);
    cld::Assert(mDisplay != nullptr, "ERROR: Failed to open X11 display!");

    mScreen = DefaultScreenOfDisplay(mDisplay);
    const int32 screenId = DefaultScreen(mDisplay);

    mWindow = XCreateSimpleWindow(mDisplay, RootWindowOfScreen(mScreen), 0, 0, width, height, 1,
                                  BlackPixel(mDisplay, screenId), WhitePixel(mDisplay, screenId));

    // Set the window title caption
    XStoreName(mDisplay, mWindow, caption);

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

    XVisualInfo* visual = glXChooseVisual(mDisplay, screenId, glxAttribs);
    cld::Assert(visual != nullptr, "ERROR: Failed to create visual info to the X11 display!");

    // Make context current
    mContext = glXCreateContext(mDisplay, visual, nullptr, GL_TRUE);
    glXMakeCurrent(mDisplay, mWindow, mContext);
}

cld::X11GLWindow::~X11GLWindow()
{
    glXDestroyContext(mDisplay, mContext);

    XDestroyWindow(mDisplay, mWindow);
    XFree(mScreen);
    XCloseDisplay(mDisplay);
}

void cld::X11GLWindow::ProcessEvents()
{
    // Check for drawing/input events
    XCheckWindowEvent(mDisplay, mWindow, ExposureMask | ButtonPressMask, &mEventHandler);
}

void cld::X11GLWindow::Move(const int32 x, const int32 y)
{
    XMoveWindow(mDisplay, mWindow, x, y);
}

void cld::X11GLWindow::Show() const
{
    XClearWindow(mDisplay, mWindow);
    XMapRaised(mDisplay, mWindow);
}

void cld::X11GLWindow::Clear(const uint32 dwColor)
{
    float r, g, b, a;
    cld::DwordToColorNormalized(dwColor, r, g, b, a);

    glClearColor(r, g, b, a);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glClearDepth(1.0f);
}

void cld::X11GLWindow::SwapBuffers()
{
    glXSwapBuffers(mDisplay, mWindow);
}