#include <concepts>
#include <iostream>

template< class Derived, class Base >
concept derived_from =
  std::is_base_of_v<Base, Derived> &&
  std::is_convertible_v<const volatile Derived*, const volatile Base*>;

int main() {

  std::cout << derived_from << std::endl;

    return 0;
}
