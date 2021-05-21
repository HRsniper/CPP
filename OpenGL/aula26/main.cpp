// http://docs.gl/
#define GLEW_BUILD
#include <GL/glew.h>

#define GLFW_DLL
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
// #include "lib/stb_image/stb_image.h"

#include "lib/imgui/imgui.h"
#include "lib/imgui/imgui_impl_glfw.h"
#include "lib/imgui/imgui_impl_opengl3.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <cmath>
#include <iostream>

#include "Debug.hpp"
#include "IndexBuffer.hpp"
#include "Renderer.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"

#include "tests/TestClearColor.hpp"
#include "tests/TestMenu.hpp"

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
  int windowHeight = 480;
  int windowWidth  = floor(windowHeight * 1.777777777777778); // 16:9
  std::cout << "W: " << windowWidth << ", H: " << windowHeight << std::endl;
  window = glfwCreateWindow(windowWidth, windowHeight, "OpenGL Course", NULL, NULL);
  if (!window) {
    std::cout << "Failed to open GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  /* Tornar o contexto da janela atual */
  glfwMakeContextCurrent(window);

  // intervalo de renderição
  // glfwSwapInterval(1); // Enable vsync

  /* glewinit somente depois do contexto*/
  if (glewInit() == GLEW_OK) {
    std::cout << "Successfully initialize GLEW" << std::endl;
  } else {
    std::cout << "Failed to initialize GLEW" << std::endl;
  }

  std::cout << "Using GL Version: " << glGetString(GL_VERSION) << std::endl;

  {
    GlCall(glEnable(GL_BLEND));
    GlCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    Renderer renderer;

    // Setup Dear ImGui context
    ImGui::CreateContext();
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460");

    test::Test *    currentTest = nullptr;
    test::TestMenu *testMenu    = new test::TestMenu(currentTest);
    currentTest                 = testMenu;

    testMenu->RegisterTest<test::TestClearColor>("Clear color");

    /* Loop até que o usuário feche a janela */
    while (!glfwWindowShouldClose(window)) {
      GlCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
      /* Renderizar */
      renderer.Clear();

      // Start the Dear ImGui frame
      ImGui_ImplOpenGL3_NewFrame();
      ImGui_ImplGlfw_NewFrame();
      ImGui::NewFrame();

      if (currentTest) {
        currentTest->OnUpdate(0.0f);
        currentTest->OnRender();

        ImGui::Begin("Test");
        if (currentTest != testMenu && ImGui::Button("< ")) {
          delete currentTest;
          currentTest = testMenu;
        }

        currentTest->OnImGuiRender();
        ImGui::End();
      }

      // Rendering
      ImGui::Render();
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

      glfwSwapBuffers(window); /* Troca os buffers frontal e traseiro */
      glfwPollEvents();        /* Pesquisar e processar eventos */
    }

    delete currentTest;
    if (currentTest != testMenu) {
      delete testMenu;
    }
  }

  // Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  // Close OpenGL window and terminate GLFW
  // glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
