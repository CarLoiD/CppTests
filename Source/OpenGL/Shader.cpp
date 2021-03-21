#include "Shader.hpp"

#include "../InlineUtils.hpp"

#include <epoxy/gl.h>

inline void LogShaderCompileError(const uint32 shaderId)
{
    int32 errorStrLenght = 0;
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &errorStrLenght);

    if (errorStrLenght)
    {
        char* buffer = new char[errorStrLenght];

        glGetShaderInfoLog(shaderId, errorStrLenght, nullptr, buffer);
        LogError(std::string("ERROR: Shader compilation failed!\n") + buffer);

        delete[] buffer;
    }
}

inline void CompileShaderInternal(const uint32 shaderId, const char* shaderCode)
{
    glShaderSource(shaderId, 1, &shaderCode, nullptr);
    glCompileShader(shaderId);

    int32 compileStatus = 0;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compileStatus);

    if (!compileStatus) {
        LogShaderCompileError(shaderId);
    }
}

cld::Shader::Shader()
{
    ShaderProgram = glCreateProgram();

    VertexShaderId   = glCreateShader(GL_VERTEX_SHADER);
    FragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
}

cld::Shader::~Shader()
{
    Unbind();

    glDeleteShader(FragmentShaderId);
    glDeleteShader(VertexShaderId);

    glDeleteProgram(ShaderProgram);
}

void cld::Shader::CompileShaderFromFile(const char* vertPath, const char* fragPath)
{
    std::ifstream vertFile(vertPath);
    std::ifstream fragFile(fragPath);
    
    Assert(vertFile.is_open(), "ERROR: Failed to open the vertex shader file!");
    const uint64 vertStrLenght = GetFileSize(vertFile);

    Assert(fragFile.is_open(), "ERROR: Failed to open the fragment shader file!");
    const uint64 fragStrLenght = GetFileSize(fragFile);

    char* vertCode = new char[vertStrLenght];
    char* fragCode = new char[fragStrLenght];

    // Read the whole chunk of shader code
    vertFile.read(vertCode, vertStrLenght);
    fragFile.read(fragCode, fragStrLenght);

    CompileShaderFromCode(vertCode, fragCode);

    delete[] vertCode;
    delete[] fragCode;
}

void cld::Shader::CompileShaderFromCode(const char* vertCode, const char* fragCode)
{
    Assert(VertexShaderId && FragmentShaderId, "ERROR: Invalid vertex/fragment shader id!");

    CompileShaderInternal(VertexShaderId, vertCode);
    CompileShaderInternal(FragmentShaderId, fragCode);

    glAttachShader(ShaderProgram, VertexShaderId);
    glAttachShader(ShaderProgram, FragmentShaderId);

    glLinkProgram(ShaderProgram);
}

void cld::Shader::Bind()
{
    glUseProgram(ShaderProgram);
}

void cld::Shader::Unbind()
{
    // Set the current bound program to an invalid one
    glUseProgram(0);
}