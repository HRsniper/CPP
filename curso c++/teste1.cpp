#include <cstdlib>
#include <iostream>

int main() {
  std::cout << "Tabela ASCII [0...127]:" << std::endl;

  for (char i = 0; i < 127; ++i) {
    std::cout << i << ((i % 16 == 15) ? '\n' : ' ');
  }

  system("pause");
  return 0;
}