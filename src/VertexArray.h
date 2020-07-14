#ifndef KOUKY3D_VERTEX_ARRAY
#define KOUKY3D_VERTEX_ARRAY


namespace Kouky3d
{
    class VertexBuffer;

    class VertexArray
    {
    public:

        VertexArray();
        ~VertexArray();

        void Bind();
        void Unbind();

        void AddBuffer(VertexBuffer& vertexBuffer);

    private:
        unsigned int m_vao;
        const float* m_vertices;
    };
}

#endif