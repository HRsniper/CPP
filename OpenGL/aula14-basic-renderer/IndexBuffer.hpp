#ifndef INDEXBUFFER_HPP
#define INDEXBUFFER_HPP

#define GLEW_BUILD
#include <GL/glew.h>

#include "Renderer.hpp"

class IndexBuffer {
private:
  unsigned int m_RendererID;
  unsigned int m_Count;

public:
  // construtor
  IndexBuffer(const unsigned int *data, unsigned int count) : m_Count(count) {

    ASSERT_F(sizeof(unsigned int) == sizeof(GLuint));

    GlCall_F_DebugBreak(glGenBuffers(1, &m_RendererID));
    GlCall_F_DebugBreak(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
    GlCall_F_DebugBreak(
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
  }
  // destrutor
  ~IndexBuffer() { GlCall_F_DebugBreak(glDeleteBuffers(1, &m_RendererID)); }

  void Bind_Vincular() const { GlCall_F_DebugBreak(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID)); }

  void Unbind_Desvincular() const { GlCall_F_DebugBreak(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0)); }

  inline unsigned int GetCount_F() const { return m_Count; }
};

#endif
