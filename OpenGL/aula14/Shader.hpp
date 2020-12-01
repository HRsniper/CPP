// #pragma once
#ifndef SHADERLAYOUT_HPP
#define SHADERLAYOUT_HPP

#define GLEW_BUILD
#include <GL/glew.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream> //Fluxo de string de entrada / saída
#include <string>  //getline()
#include <unordered_map>

#include "Renderer.hpp"

struct ShaderProgramSrc {
  std::string VertexSrc;
  std::string FragmentSrc;
};

class Shader {
private:
  unsigned int                         m_RendererID;
  std::string                          m_FilePath;
  std::unordered_map<std::string, int> m_UniformLocationCache;

  unsigned int GetUniformLocation(const std::string &name) {

    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) {
      return m_UniformLocationCache[name];
    }

    GlCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));

    // ASSERT(location != -1);
    if (location != -1) {
      std::cout << "warning: uniform " << name << " not found/exist" << std::endl;
    } /*  else {
       m_UniformLocationCache[name] = location;
     } */

    m_UniformLocationCache[name] = location;
    return location;
  }

  // https://learnopengl.com/Getting-started/Shaders
  ShaderProgramSrc ParserShader(const std::string &filepath) {
    /* lendo o arquivo com os shader */
    std::ifstream stream(filepath);

    enum class ShaderType { NONE = -1, VERTEX = 0, FRAGMENT = 1 };

    std::string       line;
    std::stringstream ss[2];
    ShaderType        tipo = ShaderType::NONE;

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

    return { ss[0].str(), ss[1].str() };
  }

  unsigned int CompileShader(const int &type, const std::string &source) {
    unsigned int id  = glCreateShader(type);
    const char * src = source.c_str();
    GlCall(glShaderSource(id, 1, &src, nullptr));
    GlCall(glCompileShader(id));

    // error
    int resultado;
    //  i=integer, v=vector
    GlCall(glGetShaderiv(id, GL_COMPILE_STATUS, &resultado));
    if (resultado == GL_FALSE) {
      int length;
      GlCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));

      // char menssagem[length];
      // Aloca memória na pilha.
      char *menssagem = (char *)malloc(length * sizeof(char));
      GlCall(glGetShaderInfoLog(id, length, &length, menssagem));

      std::cout << "falha em compilar o " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader"
                << std::endl;

      std::cout << menssagem << std::endl;

      GlCall(glDeleteShader(id));
      return 0;
    }

    return id;
  }

  unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader) {
    unsigned int programa = glCreateProgram();

    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GlCall(glAttachShader(programa, vs));
    GlCall(glAttachShader(programa, fs));

    GlCall(glLinkProgram(programa));
    GlCall(glValidateProgram(programa));

    GlCall(glDeleteShader(vs));
    GlCall(glDeleteShader(fs));

    return programa;
  }

public:
  // construtor
  Shader(const std::string &filepath) : m_FilePath(filepath), m_RendererID(0) {

    ShaderProgramSrc source = ParserShader(filepath);
    std::cout << "vertex: " << source.VertexSrc << std::endl;
    std::cout << "fragment: " << source.FragmentSrc << std::endl;

    m_RendererID = CreateShader(source.VertexSrc, source.FragmentSrc);
  }

  // destrutor
  ~Shader() { GlCall(glDeleteProgram(m_RendererID)); };

  void Bind() const { GlCall(glUseProgram(m_RendererID)); };

  void UnBind() const { GlCall(glUseProgram(0)); };

  // set uniforms
  void SetUniforms4f(const std::string &name, float v0, float v1, float v2, float v3) {

    GlCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
  };

  void SetUniforms1f(const std::string &name, float value) {

    GlCall(glUniform1f(GetUniformLocation(name), value));
  };
};

#endif
