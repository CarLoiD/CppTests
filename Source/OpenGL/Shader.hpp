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
        uint32 ShaderProgram;

        uint32 VertexShaderId;
        uint32 FragmentShaderId;
    };
}

#endif // SHADER_HPP