#ifndef TESTCLEARCOLOR_HPP
#define TESTCLEARCOLOR_HPP

#include <GL/glew.h>

#include "../Debug.hpp"
#include "../lib/imgui/imgui.h"
#include "Test.hpp"

namespace test {

class TestClearColor : public Test {
private:
  float m_ClearColor[4];

public:
  TestClearColor() : m_ClearColor { 0.2f, 0.3f, 0.0f, 1.0f } {}
  ~TestClearColor() {}

  void OnUpdate(float deltatime) override {}

  void OnRender() override {
    GlCall(glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]));

    GlCall(glClear(GL_COLOR_BUFFER_BIT));
  }

  void OnImGuiRender() override { ImGui::ColorEdit4("Clear color", m_ClearColor); }
};

} // namespace test

#endif
