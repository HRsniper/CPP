#ifndef TESTMENU_HPP
#define TESTMENU_HPP

#include <functional>
#include <string>
#include <vector>

#include "../lib/imgui/imgui.h"
#include "Test.hpp"

namespace test {

class TestMenu : public Test {
private:
  Test *&m_CurrentTest;

  std::vector<std::pair<std::string, std::function<Test *()>>> m_Tests;

public:
  TestMenu(Test *&m_CurrentTestPointer) : m_CurrentTest(m_CurrentTestPointer) {}
  ~TestMenu() {}

  void OnImGuiRender() override {
    for (auto &test : m_Tests) {
      if (ImGui::Button(test.first.c_str())) {
        m_CurrentTest = test.second();
      }
    }
  }

  template<typename T>
  void RegisterTest(const std::string &name) {
    std::cout << "Registering test: " << name << std::endl;

    m_Tests.push_back(std::make_pair(name, []() { return new T(); }));
  }
};

} // namespace test

#endif
