#ifndef TEST_HPP
#define TEST_HPP

namespace test {

class Test {
public:
  Test() {};
  virtual ~Test() {};

  virtual void OnUpdate(float deltatime) {}
  virtual void OnRender() {}
  virtual void OnImGuiRender() {}
};

} // namespace test

#endif
