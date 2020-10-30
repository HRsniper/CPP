// http://docs.gl/
#define GLEW_BUILD
#define GLFW_DLL

#include <GL/glew.h>
#include <GL/glfw3.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream> //Fluxo de string de entrada / saída
#include <string>  //getline()

#include <windows.h> //DebugBreak();

#include "aula11-abstracao-em-classes/IndexBuffer.hpp"
#include "aula11-abstracao-em-classes/Renderer.hpp"
#include "aula11-abstracao-em-classes/VertexBuffer.hpp"

struct ShaderProgramSrc_S {
    std::string VertexSrc;
    std::string FragmentSrc;
};
// https://learnopengl.com/Getting-started/Shaders
static ShaderProgramSrc_S ParserShader_F(const std::string &CaminhoDoArquivo) {
    /* lendo o arquivo com os shader */
    std::ifstream stream(CaminhoDoArquivo);

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

static unsigned int CompileShader_F(const int &type, const std::string &source) {
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

        std::cout << "falha em compilar o " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
                  << "shader" << std::endl;

        std::cout << menssagem << std::endl;

        GlCall_F_DebugBreak(glDeleteShader(id));
        return 0;
    }

    return id;
}

static unsigned int CreateShader_F(const std::string &vertexShader, const std::string &fragmentShader) {
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
int main(int argc, const char *argv[]) {
    GLFWwindow *window;

    /* Inicializou a biblioteca */
    if (!glfwInit()) {
        return -1;
    }

    // set version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Cria uma janela em modo de janela e seu contexto OpenGL */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Tornar o contexto da janela atual */
    glfwMakeContextCurrent(window);

    // intervalo de renderição
    // glfwSwapInterval(1);

    /* glewinit somente depois do contexto*/
    if (glewInit() == GLEW_OK) {
        std::cout << "glew ok" << std::endl;
    } else {
        std::cout << "glew error" << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    {

        /* array de buffer */
        /* float positions[] = {-0.5f, -0.5f, 0.5f,  -0.5f, 0.5f,  0.5f,
                             0.5f,  0.5f,  -0.5f, 0.5f,  -0.5f, -0.5f}; */

        // remover vertices duplicadas
        float positions[] = {
            -0.5f, -0.5f, // 0
            0.5f,  -0.5f, // 1
            0.5f,  0.5f,  // 2
            -0.5f, 0.5f   // 3
        };
        std::cout << positions << std::endl;

        /* index buffer */
        unsigned int indices[] = {
            0, 1, 2, // 1 triangulo
            2, 3, 0  // 1 triangulo
        };

        // error open core vao 3.3.0
        unsigned int vao;
        GlCall_F_DebugBreak(glGenVertexArrays(1, &vao));
        GlCall_F_DebugBreak(glBindVertexArray(vao));

        /*vertex buffer */
        VertexBuffer vb(positions, 4 * 2 * sizeof(float));

        /* vertex */
        GlCall_F_DebugBreak(glEnableVertexAttribArray(0));
        GlCall_F_DebugBreak(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));

        /*index buffer*/
        IndexBuffer ib(indices, 6);

        /* ShaderProgramSrc_S source =
            ParserShader_F("D:/H.R.-DEV/Arquivos-DEV/C++/OpenGL/aula06-shader/Basic.shader"); */
        ShaderProgramSrc_S source = ParserShader_F("aula06-shader/Basic460.shader");
        std::cout << "vertex: " << source.VertexSrc << std::endl;
        std::cout << "fragment: " << source.FragmentSrc << std::endl;

        unsigned int shader = CreateShader_F(source.VertexSrc, source.FragmentSrc);
        GlCall_F_DebugBreak(glUseProgram(shader));

        GlCall_F_DebugBreak(int location = glGetUniformLocation(shader, "u_Color"));
        ASSERT_F(location != -1);
        //                                        rgb(red,green,blue,alfa)    0.0=0% , 1.0=100%
        GlCall_F_DebugBreak(glUniform4f(location, 0.0f, 1.0f, 0.0f, 1.0f));

        // vertex array
        GlCall_F_DebugBreak(glBindVertexArray(0));
        GlCall_F_DebugBreak(glUseProgram(0));
        GlCall_F_DebugBreak(glBindBuffer(GL_ARRAY_BUFFER, 0));
        GlCall_F_DebugBreak(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

        // rgba
        float r = 1.0f;
        float g = 1.0f;
        float b = 0.0f;
        float alfa = 1.0f;

        float increment = 0.05f;

        /* Loop até que o usuário feche a janela */
        while (!glfwWindowShouldClose(window)) {
            /* Renderizar aqui */
            GlCall_F_DebugBreak(glClear(GL_COLOR_BUFFER_BIT));

            /* draw triangulo */
            // glDrawArrays(GL_TRIANGLES, 0, 6);

            //             gl_t,indices,tipo,null
            // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

            // vertex array
            GlCall_F_DebugBreak(glUseProgram(shader));

            GlCall_F_DebugBreak(glUniform4f(location, r, g, b, alfa));

            GlCall_F_DebugBreak(glBindVertexArray(vao));

            ib.Bind_Vincular();

            // uniform

            // lindando com errros
            GlCall_F_DebugBreak(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

            // trocando de cor uniform auto
            if (r > 1.0f) {
                increment = -0.05f;
            } else if (r < 0.0f) {
                increment = 0.05f;
            }
            r += increment;

            /* Troca os buffers frontal e traseiro */
            glfwSwapBuffers(window);

            /* Pesquisar e processar eventos */
            glfwPollEvents();
        }

        GlCall_F_DebugBreak(glDeleteProgram(shader));
    }
    glfwTerminate();
    return 0;
}