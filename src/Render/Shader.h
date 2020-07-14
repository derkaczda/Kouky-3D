#ifndef KOUKY3D_SHADER
#define KOUKY3D_SHADER

#include <string>

namespace Kouky3d
{
    class Shader
    {
    public:
        Shader(const std::string& vertexSource, const std::string& fragmentSource);
        ~Shader();

        void Bind();
        void Unbind();

    private:

        bool Compile();
        bool Link();

    private:
        unsigned int m_program;
    };
}

#endif