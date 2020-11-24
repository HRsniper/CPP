// filesystem_path_example.cpp
// compile by using: /EHsc /W4 /permissive- /std:c++17 (or /std:c++latest)
#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>

// using namespace std;
// using namespace std::filesystem;

std::wstring DisplayPathInfo() {
  // This path may or may not refer to an existing file. We are
  // examining this path string, not file system objects.
  std::filesystem::path pathToDisplay(
    L"C:/FileSystemTest/SubDir3/SubDirLevel2/File2.txt ");

  std::wostringstream wos;
  int                 i = 0;
  wos << L"Displaying path info for: " << pathToDisplay << "\n";
  for (std::filesystem::path::iterator itr = pathToDisplay.begin();
       itr != pathToDisplay.end(); ++itr) {
    wos << L"path part: " << i++ << L" = " << *itr << "\n";
  }

  wos << L"root_name() = " << pathToDisplay.root_name() << "\n"
      << L"root_path() = " << pathToDisplay.root_path() << "\n"
      << L"relative_path() = " << pathToDisplay.relative_path() << "\n"
      << L"parent_path() = " << pathToDisplay.parent_path() << "\n"
      << L"filename() = " << pathToDisplay.filename() << "\n"
      << L"stem() = " << pathToDisplay.stem() << "\n"
      << L"extension() = " << pathToDisplay.extension() << "\n";

  return wos.str();
}

int main() {
  std::wcout << DisplayPathInfo() << "\n";
  // wcout << ComparePaths() << "\n"; // see following example
  std::wcout << "\n" << L"Press Enter to exit" << "\n";
  std::wstring input;
  std::getline(std::wcin, input);
}
