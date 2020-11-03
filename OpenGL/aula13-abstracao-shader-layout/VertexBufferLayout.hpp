#ifndef VERTEXBUFFERLAYOUT_HPP
#define VERTEXBUFFERLAYOUT_HPP

#define GLEW_BUILD
#include <GL/glew.h>

#include <vector>

#include "../aula11-abstracao-em-classes/Renderer.hpp"

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSizeOfType(unsigned int type) {
        switch (type) {
        case GL_FLOAT:
            return 4;
        case GL_UNSIGNED_INT:
            return 4;
        case GL_UNSIGNED_BYTE:
            return 1;
            // default:
            //     break;
        }
        ASSERT_F(false);
        return 0;
    }
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;

public:
    // construtor
    VertexBufferLayout() : m_Stride(0) {}

    // destrutor
    ~VertexBufferLayout() {}

    template <class t> void Push_F(float count) {
        // static_assert(false, "erro em algum lugar");
        m_Elements.push_back({GL_FLOAT, (unsigned int)count, GL_FALSE});
        // sem count * faz somente um triangulo
        m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
    };

    // template<>
    /* void Push_F<float>(unsigned int count) {
        m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
        m_Stride += VertexBufferElement::GetSizeOfType(GL_FLOAT);
    }; */

    // template<>
    /* void Push_F<unsigned int>(unsigned int count) {
        m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
        m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
    }; */

    // template<>
    /* void Push_F<unsigned char>(unsigned int count) {
        m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
        m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
    };
 */
    inline const std::vector<VertexBufferElement> GetElements() const & { return m_Elements; }
    inline unsigned int GetStride() const { return m_Stride; }
};

#endif
