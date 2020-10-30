#define GLEW_BUILD
#include <GL/glew.h>

#include "VertexBuffer.hpp"
#include "Renderer.hpp"

VertexBuffer::VertexBuffer(const void *data, unsigned int size) {

    GlCall_F_DebugBreak(glGenBuffers(1, &m_RendererID));
    GlCall_F_DebugBreak(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
    GlCall_F_DebugBreak(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer() {
    GlCall_F_DebugBreak(glDeleteBuffers(1,&m_RendererID));
}

void VertexBuffer::Bind_Vincular() const {
    GlCall_F_DebugBreak(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind_Desvincular() const {
    GlCall_F_DebugBreak(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
