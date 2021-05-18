#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <GL/glew.h>

#include "Debug.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "VertexArray.hpp"

class Renderer {
public:
  void Clear() const { GlCall(glClear(GL_COLOR_BUFFER_BIT)); }

  void Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const {
    shader.Bind();
    ib.Bind();
    va.Bind();

    GlCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
  }
};

#endif
