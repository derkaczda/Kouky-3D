#include "Shader.h"
#include <glad/glad.h>
#include <iostream>

namespace Kouky3d
{
    Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource)
    {
        // TODO: move code into different methods
        // TODO: collect all sources and compile them at once
        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        const GLchar *sourceCStr = vertexSource.c_str();
        glShaderSource(vertexShader, 1, &sourceCStr, NULL);
        glCompileShader(vertexShader);

        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
            return;
        }

        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        sourceCStr = fragmentSource.c_str();
        glShaderSource(fragmentShader, 1, &sourceCStr, NULL);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
            return;
        }

        m_program = glCreateProgram();
        glAttachShader(m_program, vertexShader);
        glAttachShader(m_program, fragmentShader);
        glLinkProgram(m_program);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader); 
    }

    Shader::~Shader()
    {

    }

    void Shader::Bind()
    {
        glUseProgram(m_program);
    }

    void Shader::Unbind()
    {
        glUseProgram(0);
    }

    bool Shader::Compile()
    {
        return true;
    }

    bool Shader::Link()
    {
        return true;
    }
}