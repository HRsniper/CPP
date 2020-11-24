#include <compare>
#include <iostream>

int main() {
  double foo = -1.0;
  double bar = 0.0;

  auto res = foo <=> bar;

  if (res < 0)
    std::cout << foo << " is less than " << bar << "\n";
  else if (res == 0)
    std::cout << foo << " and" << bar << " are equal"
              << "\n";
  else if (res > 0)
    std::cout << foo << " is greater than " << bar << "\n";
}