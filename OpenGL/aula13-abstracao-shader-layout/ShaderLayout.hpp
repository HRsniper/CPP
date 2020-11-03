// #pragma once
#ifndef SHADERLAYOUT_HPP
#define SHADERLAYOUT_HPP

#include <string>
#include <unordered_map>


struct ShaderProgramSrc_S {
  std::string VertexSrc;
  std::string FragmentSrc;
};

class ShaderLayout {
  private:
  unsigned int m_RendererID;
  std::string m_FilePath;
  std::unordered_map<std::string, int> m_UniformLocationCache;

  // cache para uniforms

  unsigned int GetUniformLocation(const std::string &name);

  unsigned int CreateShader_F(const std::string &vertexShader, const std::string &fragmentShader);

  unsigned int CompileShader_F(const int &type, const std::string &source);

  ShaderProgramSrc_S ParserShader_F(const std::string &filepath);

  public:
  // construtor
  ShaderLayout(const std::string &filepath);

  // destrutor
  ~ShaderLayout();

  void Bind_VincularA() const;
  void Bind_DesVincularA() const;

  // set uniforms
  void SetUniforms4f(const std::string &name, float v0, float v1, float v2, float v3);
  void SetUniforms1f(const std::string &name, float value);
};

#endif
