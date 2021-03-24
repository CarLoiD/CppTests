#ifndef SHADER_HPP
#define SHADER_HPP

#include "../Types.hpp"

namespace cld
{
    class Shader final
    {
    public:
        Shader();
        ~Shader();

        void CompileShaderFromFile(const char* vertPath, const char* fragPath);
        void CompileShaderFromCode(const char* vertCode, const char* fragCode);
        void Bind();
        void Unbind();

    private:
        uint32 mShaderProgram;

        uint32 mVertexShaderId;
        uint32 mFragmentShaderId;
    };
}

#endif // SHADER_HPP