#ifndef RENDERER_HPP
#define RENDERER_HPP

#define GLEW_BUILD
#include <GL/glew.h>

#include <iostream>
#include <windows.h>

#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "VertexArray.hpp"

// lindando com erros macro
#define ASSERT(x) \
  if (!(x))       \
    DebugBreak();
#define GlCall(x) \
  GlClearError(); \
  x;              \
  ASSERT(GlLogCall(#x, __FILE__, __LINE__));

// lindando com erros
void GlClearError() {
  // while (!glGetError()) {
  while (glGetError() != GL_NO_ERROR) {}
}

bool GlLogCall(const char *funcao, const char *arquivo, int linha) {
  // while (unsigned int error = glGetError()) {
  while (GLenum error = glGetError()) {
    std::cout << "OPENGL ERROR: " << error << " : " << funcao << " " << arquivo << " " << linha << std::endl;
    return false;
  }
  return true;
}
// erros end

// class Renderer {
//   // private:
// public:
//   void Clear() const { GlCall(glClear(GL_COLOR_BUFFER_BIT)); }

//   void Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const {
//     shader.Bind();
//     ib.Bind();
//     va.Bind();

//     GlCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
//   };
// };

#endif
