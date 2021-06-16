#ifndef VERTEXBUFFERLAYOUT_HPP
#define VERTEXBUFFERLAYOUT_HPP

#include <GL/glew.h>
#include <vector>

#include "Debug.hpp"
#include "Renderer.hpp"

struct VertexBufferElement {
  unsigned int  type;
  unsigned int  count;
  unsigned char normalized;

  static unsigned int GetSizeOfType(unsigned int type) {
    switch (type) {
      case GL_FLOAT:
        return sizeof(GLfloat);
        // return 4;
      case GL_UNSIGNED_INT:
        return sizeof(GLuint);
        // return 4;
      case GL_UNSIGNED_BYTE:
        return sizeof(GLbyte);
        // return 1;

        // default:
        //   break;
    }

    ASSERT(false);
    return 0;
  }
};

class VertexBufferLayout {
private:
  std::vector<VertexBufferElement> m_Elements;
  unsigned int                     m_Stride;

  void Push(unsigned int type, unsigned int count, unsigned char normalized) {
    struct VertexBufferElement vertexBufferElement = { type, count, normalized };
    m_Elements.push_back(vertexBufferElement);
    m_Stride += count * VertexBufferElement::GetSizeOfType(type);
  }

public:
  // construtor
  VertexBufferLayout() : m_Stride(0) {}

  // destrutor
  ~VertexBufferLayout() {}

  void PushFloat(unsigned int count) { Push(GL_FLOAT, count, GL_FALSE); }
  void PushUnsignedInt(unsigned int count) { Push(GL_UNSIGNED_INT, count, GL_FALSE); }
  void PushUnsignedChar(unsigned int count) { Push(GL_UNSIGNED_BYTE, count, GL_TRUE); }

  inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
  inline unsigned int                           GetStride() const { return m_Stride; }
};

#endif
