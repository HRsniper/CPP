cmake_minimum_required(VERSION 3.10)

project("openGL-course" VERSION 1.0)
message("Project name: " ${CMAKE_PROJECT_NAME})

# set(CMAKE_CXX_STANDARD 17)

find_library(GLEW32 glew32 PATHS "C:/Desenvolvimento/msys64/mingw64/lib")
find_library(GLFW3 glfw3 PATHS "C:/Desenvolvimento/msys64/mingw64/lib")
find_library(OPENGL32 opengl32 PATHS "C:/Desenvolvimento/msys64/mingw64/x86_64-w64-mingw32/lib")
find_library(KERNEL32 kernel32 PATHS "C:/Desenvolvimento/msys64/mingw64/x86_64-w64-mingw32/lib")
find_library(GLU32 glu32 PATHS "C:/Desenvolvimento/msys64/mingw64/x86_64-w64-mingw32/lib")
find_library(GDI32 gdi32 PATHS "C:/Desenvolvimento/msys64/mingw64/x86_64-w64-mingw32/lib")
find_library(USER32 user32 PATHS "C:/Desenvolvimento/msys64/mingw64/x86_64-w64-mingw32/lib")
find_library(IMM32 imm32 PATHS "C:/Desenvolvimento/msys64/mingw64/x86_64-w64-mingw32/lib")
find_library(IMGUI imgui PATHS "D:/HR-DEV/C++/OpenGL/aula22/lib/imgui")

include_directories(
  "C:/Desenvolvimento/msys64/mingw64/include"
  "C:/Desenvolvimento/msys64/mingw64/x86_64-w64-mingw32/include"
  "D:/HR-DEV/C++/OpenGL/aula22/lib/imgui"
)

set(
  SOURCES
  main.cpp
  lib/stb_image/stb_image.h
  lib/imgui/imconfig.h
  lib/imgui/imgui_draw.cpp
  lib/imgui/imgui_impl_glfw.cpp
  lib/imgui/imgui_impl_glfw.h
  lib/imgui/imgui_impl_opengl3.cpp
  lib/imgui/imgui_impl_opengl3.h
  lib/imgui/imgui_internal.h
  lib/imgui/imgui_widgets.cpp
  lib/imgui/imgui.cpp
  lib/imgui/imgui.h
  lib/imgui/imstb_rectpack.h
  lib/imgui/imstb_textedit.h
  lib/imgui/imstb_truetype.h
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  ${GLEW32}
  ${GLFW3}
  ${OPENGL32}
  ${KERNEL32}
  ${GLU32}
  ${GDI32}
  ${USER32}
  ${IMM32}
  ${IMGUI}
)
