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
        cld::LogError(std::string("ERROR: Shader compilation failed!\n") + buffer);

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
    : mShaderProgram(glCreateProgram())
{
    mVertexShaderId   = glCreateShader(GL_VERTEX_SHADER);
    mFragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
}

cld::Shader::~Shader()
{
    Unbind();

    glDeleteShader(mFragmentShaderId);
    glDeleteShader(mVertexShaderId);

    glDeleteProgram(mShaderProgram);
}

void cld::Shader::CompileShaderFromFile(const char* vertPath, const char* fragPath)
{
    std::ifstream vertFile(vertPath);
    std::ifstream fragFile(fragPath);
    
    cld::Assert(vertFile.is_open(), "ERROR: Failed to open the vertex shader file!");
    const uint64 vertStrLenght = cld::GetFileSize(vertFile);

    cld::Assert(fragFile.is_open(), "ERROR: Failed to open the fragment shader file!");
    const uint64 fragStrLenght = cld::GetFileSize(fragFile);

    // Check file size
    cld::Assert(vertStrLenght > 0 && fragStrLenght > 0, "ERROR: Found empty shader file being pointed");

    char* vertCode = new char[vertStrLenght];
    char* fragCode = new char[fragStrLenght];

    // Copy from the file stream buffer to the char buffer
    // In this case a core C/C++ implementation is faster than modern C++
    // Ex: Creating a std::ostringstream and passing the rdbuf etc
    // As it deals with less memory reallocation. Simple, directly and fast.
    vertFile.read(vertCode, vertStrLenght);
    fragFile.read(fragCode, fragStrLenght);

    CompileShaderFromCode(vertCode, fragCode);

    delete[] vertCode;
    delete[] fragCode;
}

void cld::Shader::CompileShaderFromCode(const char* vertCode, const char* fragCode)
{
    cld::Assert(mVertexShaderId && mFragmentShaderId, "ERROR: Invalid vertex/fragment shader id!");

    CompileShaderInternal(mVertexShaderId, vertCode);
    CompileShaderInternal(mFragmentShaderId, fragCode);

    glAttachShader(mShaderProgram, mVertexShaderId);
    glAttachShader(mShaderProgram, mFragmentShaderId);

    glLinkProgram(mShaderProgram);
}

void cld::Shader::Bind()
{
    glUseProgram(mShaderProgram);
}

void cld::Shader::Unbind()
{
    // Set the current bound program to an invalid one
    glUseProgram(0);
}