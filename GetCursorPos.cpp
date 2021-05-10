#include <iostream>
#include <windows.h>
#include <winuser.h>

int main() {

  POINT cursorPos;

  GetCursorPos(&cursorPos);

  std::cout << cursorPos.x << " " << cursorPos.y << "\n";

  system("pause");

  return 0;
}
