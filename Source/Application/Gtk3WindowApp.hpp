#ifndef GTK3_WINDOW_APP_HPP
#define GTK3_WINDOW_APP_HPP

#include "../Application.hpp"

namespace cld
{
    class Gtk3WindowApp final : public cld::Application
    {
    public:
        void Execute(int argc, char* argv[]) override;
    };
}

#endif // GTK3_WINDOW_APP_HPP