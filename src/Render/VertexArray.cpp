#include "VertexArray.h"
#include "VertexBuffer.h"

#include <glad/glad.h>


namespace Kouky3d
{
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &m_vao);
    }

    VertexArray::~VertexArray()
    {

    }

    void VertexArray::Bind()
    {
        glBindVertexArray(m_vao);
    }

    void VertexArray::Unbind()
    {
        glBindVertexArray(0);
    }

    void VertexArray::AddBuffer(VertexBuffer& vertexBuffer)
    {
        m_vertices = vertexBuffer.Vertices();
        Bind();
        vertexBuffer.Bind();
        // TODO: fix that should not be in here
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer.Id());
        glBufferData(GL_ARRAY_BUFFER, vertexBuffer.VertexSize(), vertexBuffer.Vertices(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0); 
        vertexBuffer.Unbind();
        Unbind();
    }
}