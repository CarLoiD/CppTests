cmake_minimum_required(VERSION 3.17)

# Project
project(CppTests)

# Flags
set(GTK_INCLUDE_FLAGS "-I/usr/include/gtkmm-3.0 -I/usr/lib/gtkmm-3.0/include -I/usr/include/giomm-2.4 -I/usr/lib/giomm-2.4/include -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/glibmm-2.4 -I/usr/lib/glibmm-2.4/include -I/usr/include/sigc++-2.0 -I/usr/lib/sigc++-2.0/include -I/usr/include/gtk-3.0 -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/lzo -I/usr/include/pixman-1 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/gio-unix-2.0 -I/usr/include/cloudproviders -I/usr/include/atk-1.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/dbus-1.0 -I/usr/lib/dbus-1.0/include -I/usr/include/at-spi-2.0 -I/usr/include/cairomm-1.0 -I/usr/lib/cairomm-1.0/include -I/usr/include/pangomm-1.4 -I/usr/lib/pangomm-1.4/include -I/usr/include/atkmm-1.6 -I/usr/lib/atkmm-1.6/include -I/usr/include/gtk-3.0/unix-print -I/usr/include/gdkmm-3.0 -I/usr/lib/gdkmm-3.0/include -pthread")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GTK_INCLUDE_FLAGS}")

set(CMAKE_CXX_STANDARD 14)              # C++14
set(CMAKE_CXX_STANDARD_REQUIRED True)   # Required

# Source
file(GLOB ProjectSources CONFIGURE_DEPENDS "Source/*.hpp" "Source/*.cpp" "Source/OpenGL/*.hpp" "Source/OpenGL/*.cpp")
add_executable(${PROJECT_NAME} ${ProjectSources})

# Libs
target_link_libraries(${PROJECT_NAME} gtkmm-3.0 atkmm-1.6 gdkmm-3.0 giomm-2.4 gtk-3 gdk-3 z atk-1.0 cairo-gobject gio-2.0 pangomm-1.4 glibmm-2.4 cairomm-1.0 sigc-2.0 pangocairo-1.0 pango-1.0 harfbuzz cairo gdk_pixbuf-2.0 gobject-2.0 glib-2.0 X11 epoxy GL)