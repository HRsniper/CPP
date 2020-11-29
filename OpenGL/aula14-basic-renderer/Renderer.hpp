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
#define ASSERT_F(x) \
  if (!(x))         \
    DebugBreak();
#define GlCall_F_DebugBreak(x) \
  GlClearError_F();            \
  x;                           \
  ASSERT_F(GlLogCall_F(#x, __FILE__, __LINE__));

// lindando com erros
void GlClearError_F() {
  // while (!glGetError()) {
  while (glGetError() != GL_NO_ERROR) {}
}
bool GlLogCall_F(const char *funcao, const char *arquivo, int linha) {
  // while (unsigned int error = glGetError()) {
  while (GLenum error = glGetError()) {
    std::cout << "OPENGL ERROR: " << error << " : " << funcao << " " << arquivo << " " << linha << std::endl;
    return false;
  }
  return true;
}

class Renderer {
public:
  void Clear() const { GlCall_F_DebugBreak(glClear(GL_COLOR_BUFFER_BIT)); }

  void Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const {
    shader.Bind_VincularA();
    ib.Bind_Vincular();
    va.Bind_VincularA();

    GlCall_F_DebugBreak(glDrawElements(GL_TRIANGLES, ib.GetCount_F(), GL_UNSIGNED_INT, nullptr));
  };
}

#endif
