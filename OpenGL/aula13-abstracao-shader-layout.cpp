// http://docs.gl/
#define GLEW_BUILD
#define GLFW_DLL

#include <GL/glew.h>
#include <GL/glfw3.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream> //Fluxo de string de entrada / saída
#include <string>  //getline()

#include <windows.h> //DebugBreak();

#include "aula11-abstracao-em-classes/IndexBuffer.hpp"
#include "aula11-abstracao-em-classes/Renderer.hpp"
#include "aula11-abstracao-em-classes/VertexBuffer.hpp"

#include "aula12-abstracao-buffer-layout/VertexArray.hpp"
#include "aula12-abstracao-buffer-layout/VertexBufferLayout.hpp"

// #include "aula13-abstracao-shader-layout/ShaderLayout.hpp"
#include "aula13-abstracao-shader-layout/Shader.hpp"

int main(int argc, const char *argv[]) {
  GLFWwindow *window;

  /* Inicializou a biblioteca */
  if (!glfwInit()) {
    return -1;
  }

  // set version
  // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

    /* array de buffer */
    /* float positions[] = {-0.5f, -0.5f, 0.5f,  -0.5f, 0.5f,  0.5f,
                         0.5f,  0.5f,  -0.5f, 0.5f,  -0.5f, -0.5f}; */

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
    GlCall_F_DebugBreak(glGenVertexArrays(1, &vao));
    GlCall_F_DebugBreak(glBindVertexArray(vao));

    // buffer layout
    VertexArray va;

    /*vertex buffer */
    VertexBuffer vb(positions, 4 * 2 * sizeof(float));

    // buffer layout
    VertexBufferLayout layout;
    layout.Push_F<float>(2);
    va.AddBuffer(vb, layout);

    /*index buffer*/
    IndexBuffer ib(indices, 6);

    /* ShaderProgramSrc_S source =
        ParserShader_F("D:/HR-DEV/C++/OpenGL/aula06-shader/Basic.shader"); */
    ShaderLayout shader("aula06-shader/Basic460.shader");
    shader.Bind_VincularA();

    //                            rgb(red,green,blue,alfa)    0.0=0% , 1.0=100%
    shader.SetUniforms4f("u_Color", 0.0f, 1.0f, 0.0f, 1.0f);

    // vertex array
    va.Bind_DesVincularA();
    vb.Unbind_Desvincular();
    ib.Unbind_Desvincular();
    shader.Bind_DesVincularA();

    // rgba
    float r = 1.0f;
    float g = 1.0f;
    float b = 0.0f;
    float alfa = 1.0f;

    float increment = 0.05f;

    /* Loop até que o usuário feche a janela */
    while (!glfwWindowShouldClose(window)) {
      /* Renderizar aqui */
      GlCall_F_DebugBreak(glClear(GL_COLOR_BUFFER_BIT));

      /* draw triangulo */
      // glDrawArrays(GL_TRIANGLES, 0, 6);

      //             gl_t,indices,tipo,null
      // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

      // vertex array
      shader.Bind_VincularA();

      shader.SetUniforms4f("u_Color", r, g, b, alfa);

      ib.Bind_Vincular();
      va.Bind_VincularA();

      // uniform

      // lindando com errros
      GlCall_F_DebugBreak(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

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