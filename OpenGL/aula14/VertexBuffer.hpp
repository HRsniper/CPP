#ifndef VERTEXBUFFER_HPP
#define VERTEXBUFFER_HPP

#define GLEW_BUILD
#include <GL/glew.h>

// #include "Renderer.hpp"

class VertexBuffer {
private:
  unsigned int m_RendererID;

public:
  // construtor
  VertexBuffer(const void *data, unsigned int size) {

    GlCall(glGenBuffers(1, &m_RendererID));
    GlCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
    GlCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
  }

  // destrutor
  ~VertexBuffer() { GlCall(glDeleteBuffers(1, &m_RendererID)); }

  void Bind() const { GlCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); }

  void UnBind() const { GlCall(glBindBuffer(GL_ARRAY_BUFFER, 0)); };
};

#endif
