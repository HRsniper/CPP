#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "Debug.hpp"
#include "Renderer.hpp"
#include "lib/stb_image/stb_image.h"

class Texture {
private:
  unsigned int   m_RendererID;
  std::string    m_FilePath;
  unsigned char *m_LocalBuffer;
  int            m_Width, m_Height, m_BitsPerPixel;

public:
  // construtor
  Texture(const std::string &path) :
    m_RendererID(0), m_FilePath(path), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), m_BitsPerPixel(0) {
    stbi_set_flip_vertically_on_load(1); // virar a img de cabeça para baixo para o formato png

    m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BitsPerPixel, 4); // image

    GlCall(glGenTextures(1, &m_RendererID));
    GlCall(glBindTexture(GL_TEXTURE_2D, m_RendererID)); // Bind without slot selection

    GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

    GlCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                        m_LocalBuffer));
    Unbind();

    if (m_LocalBuffer) {
      stbi_image_free(m_LocalBuffer);
    }
  }

  // destrutor
  ~Texture() { GlCall(glDeleteTextures(1, &m_RendererID)); }

  void Bind(unsigned int slot) const {
    GlCall(glActiveTexture(GL_TEXTURE0 + slot));
    GlCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));
  }

  void Unbind() const { GlCall(glBindTexture(GL_TEXTURE_2D, 0)); }

  inline int GetWidth() const { return m_Width; }
  inline int GetHeight() const { return m_Height; }
};

#endif
