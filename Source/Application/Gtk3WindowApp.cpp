#include "Gtk3WindowApp.hpp"

#include "../Types.hpp"
#include "../InlineUtils.hpp"

#include <gtkmm.h>

void cld::Gtk3WindowApp::Execute(int argc, char* argv[])
{
    auto gtkApp = Gtk::Application::create(argc, argv, "com.carloid.cpptests.gtkwindowapp");

    Gtk::Window window;
    window.set_default_size(300, 100);
    window.set_border_width(20);
    window.set_position(Gtk::WindowPosition::WIN_POS_CENTER);
    window.override_background_color(Gdk::RGBA("#202020"));    // Dark Grey background
    window.set_title("CppTests - Gtk3WindowApp");

    Gtk::Button btnHello("Hello World!", true);
    btnHello.set_size_request(200, 50);
    btnHello.show();

    btnHello.signal_clicked().connect([this] {
        std::cout << "Pressed inside lambda!\n";
    });

    window.add(btnHello);

    int32 ret = gtkApp->run(window);
    std::cout << "Exit with code " << ret << '\n';

    cld::ClearConsole();
}