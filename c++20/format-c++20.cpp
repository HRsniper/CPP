#include <format>
#include <iostream>

int main() {
  std::cout << std::format("Hello {} ! \n", "world");
  return 0;
}

// Output:
// Hello world!