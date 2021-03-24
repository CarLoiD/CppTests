#ifndef INLINE_UTILS_HPP
#define INLINE_UTILS_HPP

#include "Types.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

namespace cld
{
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
        std::putchar(static_cast<int32>('\n'));

        const std::string logTxt = "\033[1;31m" + message + "\033[0m\n";
        std::cout << logTxt;
    }

#ifndef NDEBUG
    inline void Assert(const bool expression, const std::string& message)
    {
        if (!expression) {
            LogError(message);
            std::exit(-1);
        }
    }
#else
    #define Assert(expression, message)
#endif

    inline void DwordToColor(const uint32 dword, float& r, float& g, float& b, float& a)
    {
        r = (float)((dword & 0xFF000000) >> 24);
        g = (float)((dword & 0x00FF0000) >> 16);
        b = (float)((dword & 0x0000FF00) >> 8);
        a = (float)((dword & 0x000000FF));
    }

    inline void DwordToColorNormalized(const uint32 dword, float& r, float& g, float& b, float& a)
    {
        DwordToColor(dword, r, g, b, a);
        r /= 255.0f;
        g /= 255.0f;
        b /= 255.0f;
        a /= 255.0f;
    }

    inline void ColorToDword(const uint32 r, const uint32 g, const uint32 b, const uint32 a, uint32& dword)
    {
        dword = (r << 24) | (g << 16) | (b << 8) | (a);
    }

    inline uint64 GetFileSize(std::ifstream& file)
    {
        file.seekg(0, std::ios::end);
        
        const uint64 size = (uint64) file.tellg();
        file.seekg(0, std::ios::beg);

        return size;
    }

    template <typename T>
    inline std::string ToString(const T& input)
    {
        std::stringstream sstream;
        sstream << input;

        return sstream.str();
    }
}

#endif // INLINE_UTILS_HPP