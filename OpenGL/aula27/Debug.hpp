#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <GL/glew.h>
#include <iostream>
#include <windows.h> //DebugBreak();

// lindando com erros (macro)
#define ASSERT(x) \
  if (!(x))       \
    DebugBreak();

// lindando com erros
void GlClearError() {
  // while (!glGetError()) {
  while (glGetError() != GL_NO_ERROR) {}
}

bool GlLogCall(const char *func, const char *file, int line) {
  // while (unsigned int error = glGetError()) {
  while (GLenum error = glGetError()) {
    std::cout << "OPENGL ERROR: " << error << " : " << func << " " << file << " " << line << std::endl;
    return false;
  }
  return true;
}

#define GlCall(x) \
  GlClearError(); \
  x;              \
  ASSERT(GlLogCall(#x, __FILE__, __LINE__));

#endif
