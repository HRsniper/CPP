// http://docs.gl/
#define GLEW_BUILD
#include <GL/glew.h>

#define GLFW_DLL
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
// #include "lib/stb_image/stb_image.h"

// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>

#include <iostream>

#include "Debug.hpp"
#include "IndexBuffer.hpp"
#include "Renderer.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"

int main(int argc, const char *argv[]) {
  GLFWwindow *window;

  /* Inicializou a biblioteca */
  if (!glfwInit()) {
    std::cout << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  // set version
  // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
  // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  /* Cria uma janela em modo de janela e seu contexto OpenGL */
  window = glfwCreateWindow(640, 480, "OpenGL Course", NULL, NULL);
  if (!window) {
    std::cout << "Failed to open GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  /* Tornar o contexto da janela atual */
  glfwMakeContextCurrent(window);

  // intervalo de renderição
  // glfwSwapInterval(1);

  /* glewinit somente depois do contexto*/
  if (glewInit() == GLEW_OK) {
    std::cout << "Successfully initialize GLEW" << std::endl;
  } else {
    std::cout << "Failed to initialize GLEW" << std::endl;
  }

  std::cout << "Using GL Version: " << glGetString(GL_VERSION) << std::endl;

  {

    // remover vertices duplicadas
    float positions[] = {
      -0.5f, -0.5f, 0.0f, 0.0f, // 0
      0.5f,  -0.5f, 1.0f, 0.0f, // 1
      0.5f,  0.5f,  1.0f, 1.0f, // 2
      -0.5f, 0.5f,  0.0f, 1.0f  // 3
    };

    /* index buffer */
    unsigned int indices[] = {
      0, 1, 2, // 1 triangulo
      2, 3, 0  // 1 triangulo
    };

    GlCall(glEnable(GL_BLEND));
    GlCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    VertexArray        va;                                   // vertex array
    VertexBuffer       vb(positions, 4 * 4 * sizeof(float)); // vertex buffer
    IndexBuffer        ib(indices, 6);                       // index buffer
    VertexBufferLayout layout;                               // buffer layout

    layout.PushFloat(2);
    layout.PushFloat(2);
    va.AddBuffer(vb, layout);

    // glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);

    Shader shader("shaders/Basic.shader");
    shader.Bind();

    Texture texture("textures/opengl.png");
    texture.Bind(0);
    shader.SetUniform1i("u_Texture", 0);

    // rgba(red,green,blue,alfa)    0.0=0% , 1.0=100%
    float r    = 1.0f;
    float g    = 1.0f;
    float b    = 0.0f;
    float alfa = 1.0f;

    float increment = 0.05f;

    Renderer renderer;

    /* Loop até que o usuário feche a janela */
    while (!glfwWindowShouldClose(window)) {
      /* Renderizar */
      renderer.Clear();

      // vertex array
      shader.Bind();
      shader.SetUniform4f("u_Color", r, g, b, alfa);

      renderer.Draw(va, ib, shader);

      glfwSwapBuffers(window); /* Troca os buffers frontal e traseiro */
      glfwPollEvents();        /* Pesquisar e processar eventos */

      // trocando de cor uniform auto
      if (r > 1.0f) {
        increment = -0.05f;
      } else if (r < 0.0f) {
        increment = 0.05f;
      }

      r += increment;
    }
  }

  // Close OpenGL window and terminate GLFW
  glfwTerminate();

  return 0;
}
