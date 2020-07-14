#include "VertexBuffer.h"
#include <glad/glad.h>

namespace Kouky3d
{
    VertexBuffer::VertexBuffer(float* vertices, size_t size) : 
        m_vertices(vertices),
        m_vertexSize(size)
    {
        glGenBuffers(1, &m_vbo);
        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
        Unbind();
    }

    VertexBuffer::~VertexBuffer()
    {

    }

    void VertexBuffer::Bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    }

    void VertexBuffer::Unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}