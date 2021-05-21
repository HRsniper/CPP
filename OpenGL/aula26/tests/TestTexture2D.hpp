#ifndef TESTTEXTURE2D_HPP
#define TESTTEXTURE2D_HPP

#include <GL/glew.h>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

#include "../Debug.hpp"
#include "../IndexBuffer.hpp"
#include "../Renderer.hpp"
#include "../Shader.hpp"
#include "../Texture.hpp"
#include "../VertexArray.hpp"
#include "../VertexBuffer.hpp"
#include "../VertexBufferLayout.hpp"
#include "../lib/imgui/imgui.h"
#include "Test.hpp"

namespace test {

class TestTexture2D : public Test {
private:
  std::unique_ptr<VertexArray>        m_VertexArray;
  std::unique_ptr<IndexBuffer>        m_IndexBuffer;
  std::unique_ptr<VertexBuffer>       m_VertexBuffer;
  std::unique_ptr<VertexBufferLayout> m_Layout;
  std::unique_ptr<Shader>             m_Shader;
  std::unique_ptr<Texture>            m_Texture;
  std::unique_ptr<Renderer>           m_Renderer;

  // float        m_ClearColor[4];
  // float        m_Positions[16];
  // unsigned int m_Indices[6];

  // model and mvp will be created per object per draw
  glm::mat4 m_Projection;
  glm::mat4 m_View;

  glm::vec3 m_TranslationA;
  glm::vec3 m_TranslationB;

  int m_WindowHeight;
  int m_WindowWidth;

public:
  TestTexture2D() :
    m_WindowHeight(480), m_WindowWidth(floor(m_WindowHeight * 1.777777777777778)), // 16:9
    m_TranslationA(200, 200, 0),                                                   // 200x 200y 0z
    m_TranslationB(400, 400, 0),                                                   // 400x 400y 0z
    m_Projection(glm::ortho(0.0f, float(m_WindowWidth), 0.0f, float(m_WindowHeight), -1.0f, 1.0f)),
    m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))) {

    // -50, 50 = center
    float positions[] = {
      -50.0f, -50.0f, 0.0f, 0.0f, // 0
      50.0f,  -50.0f, 1.0f, 0.0f, // 1
      50.0f,  50.0f,  1.0f, 1.0f, // 2
      -50.0f, 50.0f,  0.0f, 1.0f  // 3
    };

    // index buffer
    unsigned int indices[] = {
      0, 1, 2, // 1 triangulo
      2, 3, 0  // 1 triangulo
    };

    GlCall(glEnable(GL_BLEND));
    GlCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    m_VertexArray  = std::make_unique<VertexArray>();                                  // vertex array
    m_VertexBuffer = std::make_unique<VertexBuffer>(positions, 4 * 4 * sizeof(float)); // vertex buffer

    VertexBufferLayout layout; // buffer layout

    layout.PushFloat(2);
    layout.PushFloat(2);
    m_VertexArray->AddBuffer(*m_VertexBuffer, layout);

    m_IndexBuffer = std::make_unique<IndexBuffer>(indices, 6); // index buffer

    m_Shader = std::make_unique<Shader>("shaders/Basic.shader"); // shader
    m_Shader->Bind();

    m_Texture = std::make_unique<Texture>("textures/opengl.png"); // texture
    m_Shader->SetUniform1i("u_Texture", 0);
  }

  ~TestTexture2D() {}

  void OnUpdate(float deltatime) override {}

  void OnRender() override {
    GlCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
    GlCall(glClear(GL_COLOR_BUFFER_BIT));

    Renderer renderer;
    m_Texture->Bind(0);

    {
      glm::mat4 model               = glm::translate(glm::mat4(1.0f), m_TranslationA);
      glm::mat4 modelViewProjection = m_Projection * m_View * model;

      m_Shader->Bind();
      m_Shader->SetUniformMat4f("u_MVP", modelViewProjection);
      renderer.Draw(*m_VertexArray, *m_IndexBuffer, *m_Shader);
    }

    {
      glm::mat4 model               = glm::translate(glm::mat4(1.0f), m_TranslationB);
      glm::mat4 modelViewProjection = m_Projection * m_View * model;

      m_Shader->Bind();
      m_Shader->SetUniformMat4f("u_MVP", modelViewProjection);
      renderer.Draw(*m_VertexArray, *m_IndexBuffer, *m_Shader);
    }
  }

  void OnImGuiRender() override {
    glm::vec3 m_TranslationA(200, 200, 0);
    glm::vec3 m_TranslationB(400, 400, 0);

    // Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
    ImGui::Begin("OpenGL Course");

    ImGui::Text("X Y Z");
    // Edit 1 float using a slider from 0.0f to width of windown in float
    ImGui::SliderFloat3("Translation A", &m_TranslationA.x, 0.0f, float(m_WindowWidth));
    ImGui::SliderFloat3("Translation B", &m_TranslationB.x, 0.0f, float(m_WindowWidth));

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
                ImGui::GetIO().Framerate);

    ImGui::End();
  }
};

} // namespace test

#endif
