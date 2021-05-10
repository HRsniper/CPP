// #pragma once
#ifndef SHADERLAYOUT_HPP
#define SHADERLAYOUT_HPP

#include <GL/glew.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <malloc.h>
#include <sstream> //Fluxo de string de entrada / saída
#include <string>  //getline()
#include <unordered_map>

#include "Debug.hpp"
#include "Renderer.hpp"

struct ShaderProgramSource {
  std::string VertexSource;
  std::string FragmentSource;
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
      std::cout << "WARNING: uniform " << name << " not found/exist" << std::endl;
    }
    /* else {
       m_UniformLocationCache[name] = location;
     } */

    m_UniformLocationCache[name] = location;

    return location;
  }

  enum ShaderType { NONE = -1, VERTEX = 0, FRAGMENT = 1 };

  // https://learnopengl.com/Getting-started/Shaders
  struct ShaderProgramSource ParserShader(const std::string &filepath) {
    // lendo o arquivo com os shader
    std::ifstream stream(filepath);

    std::string       line;
    std::stringstream ss[2];
    ShaderType        type = NONE;

    while (std::getline(stream, line)) {
      if (line.find("#shader") != std::string::npos) {
        if (line.find("vertex") != std::string::npos) {
          type = VERTEX; // set para o modo vertex
        } else if (line.find("fragment") != std::string::npos) {
          type = FRAGMENT; // set para o modo fragment
        }
      } else {
        // [index]
        ss[(int)type] << line << "\n";
      }
    }

    // return { ss[0].str(), ss[1].str() };
    struct ShaderProgramSource shaderProgramSource = { ss[0].str(), ss[1].str() };
    return shaderProgramSource;
  }

  unsigned int CompileShader(const int &type, const std::string &source) {
    GlCall(unsigned int id = glCreateShader(type));
    const char *src = source.c_str();
    GlCall(glShaderSource(id, 1, &src, nullptr));
    GlCall(glCompileShader(id));

    // error handling
    int result;
    //  i=integer, v=vector
    GlCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
    std::cout << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader compile status: " << result
              << std::endl;

    if (result == GL_FALSE) {
      int length;
      GlCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
      // char message[length]; Aloca memória na pilha.
      char *message = (char *)alloca(length * sizeof(char));
      GlCall(glGetShaderInfoLog(id, length, &length, message));

      std::cout << "failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader"
                << std::endl;
      std::cout << message << std::endl;

      GlCall(glDeleteShader(id));
      return 0;
    }

    return id;
  }

  unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs      = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs      = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GlCall(glAttachShader(program, vs));
    GlCall(glAttachShader(program, fs));

    GlCall(glLinkProgram(program));

    GLint programLinked;
    GlCall(glGetProgramiv(program, GL_LINK_STATUS, &programLinked));
    std::cout << "program link status: " << programLinked << std::endl;

    if (programLinked != GL_TRUE) {
      GLsizei logLength = 0;
      GLchar  message[1024];
      GlCall(glGetProgramInfoLog(program, 1024, &logLength, message));
      std::cout << "failed to link program" << std::endl;
      std::cout << message << std::endl;
    }

    GlCall(glValidateProgram(program));

    GlCall(glDeleteShader(vs));
    GlCall(glDeleteShader(fs));

    return program;
  }

public:
  // construtor
  Shader(const std::string &filepath) : m_FilePath(filepath), m_RendererID(0) {

    ShaderProgramSource source = ParserShader(filepath);
    // std::cout << "VERTEX: " << source.VertexSource << std::endl;
    // std::cout << "FRAGMENT: " << source.FragmentSource << std::endl;

    m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);

    GlCall(glUseProgram(m_RendererID));
  }

  // destrutor
  ~Shader() { GlCall(glDeleteProgram(m_RendererID)); };

  void Bind() const { GlCall(glUseProgram(m_RendererID)); };

  void Unbind() const { GlCall(glUseProgram(0)); };

  // set uniforms
  void SetUniforms4f(const std::string &name, float f0, float f1, float f2, float f3) {

    GlCall(glUniform4f(GetUniformLocation(name), f0, f1, f2, f3));
  };

  void SetUniforms1f(const std::string &name, float value) {

    GlCall(glUniform1f(GetUniformLocation(name), value));
  };

  // void SetUniforms1i(const std::string &name, int value) {
  //   GlCall(glUniform1i(GetUniformLocation(name), value));
  // }
};

#endif
