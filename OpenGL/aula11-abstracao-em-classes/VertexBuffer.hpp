#ifndef VERTEXBUFFER_HPP
#define VERTEXBUFFER_HPP

#define GLEW_BUILD
#include <GL/glew.h>

#include "Renderer.hpp"
class VertexBuffer {
private:
    unsigned int m_RendererID;

public:
    // construtor
    VertexBuffer(const void *data, unsigned int size) {

        GlCall_F_DebugBreak(glGenBuffers(1, &m_RendererID));
        GlCall_F_DebugBreak(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
        GlCall_F_DebugBreak(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
    }

    // destrutor
    ~VertexBuffer() { GlCall_F_DebugBreak(glDeleteBuffers(1, &m_RendererID)); }

    void Bind_Vincular() const { GlCall_F_DebugBreak(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); }

    void Unbind_Desvincular() const { GlCall_F_DebugBreak(glBindBuffer(GL_ARRAY_BUFFER, 0)); };
};

#endif
