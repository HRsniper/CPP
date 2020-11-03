#define GLEW_BUILD
#include <GL/glew.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream> //Fluxo de string de entrada / saída
#include <string>  //getline()

#include "../aula11-abstracao-em-classes/Renderer.hpp"

#include "ShaderLayout.hpp"

// construtor
ShaderLayout::ShaderLayout(const std::string &filepath) : m_FilePath(filepath), m_RendererID(0) {

  ShaderProgramSrc_S source = ParserShader_F(filepath);
  std::cout << "vertex: " << source.VertexSrc << std::endl;
  std::cout << "fragment: " << source.FragmentSrc << std::endl;

  m_RendererID = CreateShader_F(source.VertexSrc, source.FragmentSrc);
}

// destrutor
ShaderLayout::~ShaderLayout() { GlCall_F_DebugBreak(glDeleteProgram(m_RendererID)); };

// https://learnopengl.com/Getting-started/Shaders
ShaderProgramSrc_S ShaderLayout::ParserShader_F(const std::string &filepath) {
  /* lendo o arquivo com os shader */
  std::ifstream stream(filepath);

  enum class ShaderType { NONE = -1, VERTEX = 0, FRAGMENT = 1 };

  std::string line;
  std::stringstream ss[2];
  ShaderType tipo = ShaderType::NONE;

  while (std::getline(stream, line)) {
    if (line.find("#shader") != std::string::npos) {

      if (line.find("vertex") != std::string::npos) {
        /* set para o modo vertex */
        tipo = ShaderType::VERTEX;
      } else if (line.find("fragment") != std::string::npos) {
        /* set para o modo fragment */
        tipo = ShaderType::FRAGMENT;
      }
    } else {
      /* [index] */
      ss[(int)tipo] << line << "\n";
    }
  }

  return {ss[0].str(), ss[1].str()};
}

unsigned int ShaderLayout::CompileShader_F(const int &type, const std::string &source) {
  unsigned int id = glCreateShader(type);
  const char *src = source.c_str();
  GlCall_F_DebugBreak(glShaderSource(id, 1, &src, nullptr));
  GlCall_F_DebugBreak(glCompileShader(id));

  // error
  int resultado;
  //  i=integer, v=vector
  GlCall_F_DebugBreak(glGetShaderiv(id, GL_COMPILE_STATUS, &resultado));
  if (resultado == GL_FALSE) {
    int length;
    GlCall_F_DebugBreak(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));

    // char menssagem[length];
    // Aloca memória na pilha.
    char *menssagem = (char *)malloc(length * sizeof(char));
    GlCall_F_DebugBreak(glGetShaderInfoLog(id, length, &length, menssagem));

    std::cout << "falha em compilar o " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader"
              << std::endl;

    std::cout << menssagem << std::endl;

    GlCall_F_DebugBreak(glDeleteShader(id));
    return 0;
  }

  return id;
}

unsigned int ShaderLayout::CreateShader_F(const std::string &vertexShader,
                                          const std::string &fragmentShader) {
  unsigned int programa = glCreateProgram();

  unsigned int vs = CompileShader_F(GL_VERTEX_SHADER, vertexShader);
  unsigned int fs = CompileShader_F(GL_FRAGMENT_SHADER, fragmentShader);

  GlCall_F_DebugBreak(glAttachShader(programa, vs));
  GlCall_F_DebugBreak(glAttachShader(programa, fs));

  GlCall_F_DebugBreak(glLinkProgram(programa));
  GlCall_F_DebugBreak(glValidateProgram(programa));

  GlCall_F_DebugBreak(glDeleteShader(vs));
  GlCall_F_DebugBreak(glDeleteShader(fs));

  return programa;
}

void ShaderLayout::Bind_VincularA() const { GlCall_F_DebugBreak(glUseProgram(m_RendererID)); };

void ShaderLayout::Bind_DesVincularA() const { GlCall_F_DebugBreak(glUseProgram(0)); };

// set uniforms
void ShaderLayout::SetUniforms4f(const std::string &name, float v0, float v1, float v2, float v3) {

  GlCall_F_DebugBreak(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
};

void ShaderLayout::SetUniforms1f(const std::string &name, float value) {

    GlCall_F_DebugBreak(glUniform4f(GetUniformLocation(name), value));
  };

unsigned int ShaderLayout::GetUniformLocation(const std::string &name) {


    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) {
      return m_UniformLocationCache[name];
    }

    GlCall_F_DebugBreak(int location = glGetUniformLocation(m_RendererID, name.c_str()));

    // ASSERT_F(location != -1);
    if (location != -1) {
      std::cout << "warning: uniform " << name << " not found/exist" << std::endl;
    }/*  else {
      m_UniformLocationCache[name] = location;
    } */

      m_UniformLocationCache[name] = location;
    return location;
  }