#ifndef VERTEXARRAY_HPP
#define VERTEXARRAY_HPP

// #define GLEW_BUILD
// #include <GL/glew.h>

#include "Renderer.hpp"
#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"

class VertexBufferLayout;

class VertexArray {
private:
  unsigned int m_RendererID;

public:
  // construtor
  VertexArray() { GlCall_F_DebugBreak(glGenVertexArrays(1, &m_RendererID)); }

  // destrutor
  ~VertexArray() { GlCall_F_DebugBreak(glDeleteVertexArrays(1, &m_RendererID)); }

  void AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) {
    Bind_VincularA();
    vb.Bind_Vincular();

    // layout
    const auto & elements = layout.GetElements();
    unsigned int offset   = 0;

    for (unsigned int i = 0; i < elements.size(); i++) {
      const auto &element = elements[i];

      GlCall_F_DebugBreak(glEnableVertexAttribArray(i));
      GlCall_F_DebugBreak(glVertexAttribPointer(i, element.count, element.type, element.normalized,
                                                layout.GetStride(), (const void *)offset));
      offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
  }

  void Bind_VincularA() const { GlCall_F_DebugBreak(glBindVertexArray(m_RendererID)); }
  void Bind_DesVincularA() const { GlCall_F_DebugBreak(glBindVertexArray(0)); }
};

#endif
