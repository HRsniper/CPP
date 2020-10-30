#define GLEW_BUILD
#include <GL/glew.h>

#include <iostream>

#include "Renderer.hpp"

void GlClearError_F() {
    // while (!glGetError()) {
    while (glGetError() != GL_NO_ERROR) {
    }
}
bool GlLogCall_F(const char *funcao, const char *arquivo, int linha) {
    // while (unsigned int error = glGetError()) {
    while (GLenum error = glGetError()) {
        std::cout << "OPENGL ERROR: " << error << " : " << funcao << " " << arquivo << " " << linha
                  << std::endl;
        return false;
    }
    return true;
}
// erros end