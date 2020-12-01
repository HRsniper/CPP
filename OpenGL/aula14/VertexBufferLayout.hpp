#ifndef VERTEXBUFFERLAYOUT_HPP
#define VERTEXBUFFERLAYOUT_HPP

#define GLEW_BUILD
#include <GL/glew.h>

#include <vector>

#include "Renderer.hpp"

struct VertexBufferElement {
  unsigned int  type;
  unsigned int  count;
  unsigned char normalized;

  static unsigned int GetSizeOfType(unsigned int type) {
    switch (type) {
      case GL_FLOAT:
        return 4;
      case GL_UNSIGNED_INT:
        return 4;
      case GL_UNSIGNED_BYTE:
        return 1;
        // default:
        //     break;
    }
    ASSERT(false);
    return 0;
  }
};

class VertexBufferLayout {
private:
  std::vector<VertexBufferElement> m_Elements;
  unsigned int                     m_Stride;

public:
  // construtor
  VertexBufferLayout() : m_Stride(0) {}

  // destrutor
  ~VertexBufferLayout() {}

  template<class t>
  void Push(float count) {
    // static_assert(false, "erro em algum lugar");
    m_Elements.push_back({ GL_FLOAT, (unsigned int)count, GL_FALSE });
    // sem count * faz somente um triangulo
    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
  };

  inline const std::vector<VertexBufferElement> GetElements() const & { return m_Elements; }
  inline unsigned int                           GetStride() const { return m_Stride; }
};

#endif
