#ifndef INDEXBUFFER_HPP
#define INDEXBUFFER_HPP

#include <GL/glew.h>

#include "Debug.hpp"

class IndexBuffer {
private:
  unsigned int m_RendererID;
  unsigned int m_Count;

public:
  // construtor
  IndexBuffer(const unsigned int *indices, unsigned int count) : m_Count(count) {

    ASSERT(sizeof(unsigned int) == sizeof(GLuint));

    GlCall(glGenBuffers(1, &m_RendererID));
    GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
    GlCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW));
  }

  // destrutor
  ~IndexBuffer() { GlCall(glDeleteBuffers(1, &m_RendererID)); }

  void Bind() const { GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID)); }

  void Unbind() const { GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0)); }

  inline unsigned int GetCount() const { return m_Count; }
};

#endif
