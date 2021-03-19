#ifndef INLINE_UTILS_HPP
#define INLINE_UTILS_HPP

#include <iostream>
#include <string>

inline void ClearConsole()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

inline void HoldNextInput()
{
    std::cin.ignore();
    std::cin.get();
}

inline void LogError(const std::string& message)
{
    std::cout << '\n';
    ClearConsole();

    const std::string logTxt = "\033[1;31m" + message + "\033[0m\n";
    std::cout << logTxt;
}

inline void Assert(const bool expression, const std::string& message)
{
    if (!expression) {
        LogError(message);
        std::exit(-1);
    }
}

inline void DwordToColor(const uint32_t dword, float& r, float& g, float& b, float& a)
{
    r = (float)((dword & 0xFF000000) >> 24);
    g = (float)((dword & 0x00FF0000) >> 16);
    b = (float)((dword & 0x0000FF00) >> 8);
    a = (float)((dword & 0x000000FF));
}

inline void DwordToColorNormalized(const uint32_t dword, float& r, float& g, float& b, float& a)
{
    DwordToColor(dword, r, g, b, a);
    r /= 255.0f;
    g /= 255.0f;
    b /= 255.0f;
    a /= 255.0f;
}

inline void ColorToDword(const uint32_t r, const uint32_t g, const uint32_t b, const uint32_t a, uint32_t& dword)
{
    dword = (r << 24) | (g << 16) | (b << 8) | (a);
}

#endif // INLINE_UTILS_HPP