#ifndef KOUKY3D_VERTEX_BUFFER
#define KOUKY3D_VERTEX_BUFFER

namespace Kouky3d
{
    class VertexBuffer
    {
    public:
        
        VertexBuffer(float* vertices, size_t size);
        ~VertexBuffer();

        void Bind();
        void Unbind();

        inline unsigned int Id() const { return m_vbo; }
        inline float* Vertices() const { return m_vertices; }
        inline size_t VertexSize() const { return m_vertexSize; }

    private:
        unsigned int m_vbo;
        float* m_vertices;
        size_t m_vertexSize;
    };
}

#endif