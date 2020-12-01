// http://docs.gl/
#define GLEW_BUILD
#define GLFW_DLL
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>   //Fluxo de string de entrada / saída
#include <string>    //getline()
#include <windows.h> //DebugBreak();

#include "aula14/IndexBuffer.hpp"
#include "aula14/Renderer.hpp"
#include "aula14/Shader.hpp"
#include "aula14/VertexArray.hpp"
#include "aula14/VertexBuffer.hpp"
#include "aula14/VertexBufferLayout.hpp"

int main(int argc, const char *argv[]) {
  GLFWwindow *window;

  /* Inicializou a biblioteca */
  if (!glfwInit()) {
    return -1;
  }

  /* Cria uma janela em modo de janela e seu contexto OpenGL */
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  /* Tornar o contexto da janela atual */
  glfwMakeContextCurrent(window);

  // intervalo de renderição
  // glfwSwapInterval(1);

  /* glewinit somente depois do contexto*/
  if (glewInit() == GLEW_OK) {
    std::cout << "glew ok" << std::endl;
  } else {
    std::cout << "glew error" << std::endl;
  }

  std::cout << glGetString(GL_VERSION) << std::endl;

  {

    // remover vertices duplicadas
    float positions[] = {
      -0.5f, -0.5f, // 0
      0.5f,  -0.5f, // 1
      0.5f,  0.5f,  // 2
      -0.5f, 0.5f   // 3
    };
    std::cout << positions << std::endl;

    /* index buffer */
    unsigned int indices[] = {
      0, 1, 2, // 1 triangulo
      2, 3, 0  // 1 triangulo
    };

    // error open core vao 3.3.0
    unsigned int vao;
    GlCall(glGenVertexArrays(1, &vao));
    GlCall(glBindVertexArray(vao));

    // buffer layout
    VertexArray va;

    /*vertex buffer */
    VertexBuffer vb(positions, 4 * 2 * sizeof(float));

    // buffer layout
    VertexBufferLayout layout;
    layout.Push<float>(2);
    va.AddBuffer(vb, layout);

    /*index buffer*/
    IndexBuffer ib(indices, 6);

    Shader shader("aula14/Basic460.shader");
    shader.Bind();

    //                            rgb(red,green,blue,alfa)    0.0=0% , 1.0=100%
    shader.SetUniforms4f("u_Color", 0.0f, 1.0f, 0.0f, 1.0f);

    // vertex array
    va.UnBind();
    vb.UnBind();
    ib.UnBind();
    shader.UnBind();

    // rgba
    float r    = 1.0f;
    float g    = 1.0f;
    float b    = 0.0f;
    float alfa = 1.0f;

    float increment = 0.05f;

    /* Loop até que o usuário feche a janela */
    while (!glfwWindowShouldClose(window)) {
      /* Renderizar aqui */
      GlCall(glClear(GL_COLOR_BUFFER_BIT));

      // vertex array
      shader.Bind();

      shader.SetUniforms4f("u_Color", r, g, b, alfa);

      ib.Bind();
      va.Bind();

      // uniform

      // lindando com errros
      GlCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

      // trocando de cor uniform auto
      if (r > 1.0f) {
        increment = -0.05f;
      } else if (r < 0.0f) {
        increment = 0.05f;
      }
      r += increment;

      /* Troca os buffers frontal e traseiro */
      glfwSwapBuffers(window);

      /* Pesquisar e processar eventos */
      glfwPollEvents();
    }
  }

  glfwTerminate();
  return 0;
}