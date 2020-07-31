#ifndef KOUKY3D_SHADER
#define KOUKY3D_SHADER

#include <string>
#include <glm/glm.hpp>

namespace Kouky3d
{
    class Shader
    {
    public:
        Shader(const std::string& vertexSource, const std::string& fragmentSource);
        ~Shader();

        void Bind();
        void Unbind();

        void Uniform(const std::string& name, const glm::mat4& matrix);
        void Uniform(const std::string& name, const glm::mat3& matrix);

    private:

        bool Compile();
        bool Link();

    private:
        unsigned int m_program;
    };
}

#endif