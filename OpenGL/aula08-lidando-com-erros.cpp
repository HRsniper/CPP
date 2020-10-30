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

// lindando com erros macro
#define ASSERT_F(x)                                                                                        \
    if (!(x))                                                                                              \
        DebugBreak();
#define GlCall_F(x)                                                                                        \
    GlClearError_F();                                                                                      \
    x;                                                                                                     \
    ASSERT_F(GlLogCall_F(#x, __FILE__, __LINE__));

// lindando com erros
static void GlClearError_F() {
    // while (!glGetError()) {
    while (glGetError() != GL_NO_ERROR) {
    }
}
static bool GlLogCall_F(const char *funcao, const char *arquivo, int linha) {
    // while (unsigned int error = glGetError()) {
    while (GLenum error = glGetError()) {
        std::cout << "OPENGL ERROR: " << error << " : " << funcao << " " << arquivo << " " << linha
                  << std::endl;
        return false;
    }
    return true;
}
// erros end

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
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    // error
    int resultado;
    //  i=integer, v=vector
    glGetShaderiv(id, GL_COMPILE_STATUS, &resultado);
    if (resultado == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

        // char menssagem[length];
        // Aloca memória na pilha.
        char *menssagem = (char *)malloc(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, menssagem);

        std::cout << "falha em compilar o " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
                  << "shader" << std::endl;

        std::cout << menssagem << std::endl;

        glDeleteShader(id);
        return 0;
    }

    return id;
}

static unsigned int CreateShader_F(const std::string &vertexShader, const std::string &fragmentShader) {
    unsigned int programa = glCreateProgram();

    unsigned int vs = CompileShader_F(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader_F(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(programa, vs);
    glAttachShader(programa, fs);

    glLinkProgram(programa);
    glValidateProgram(programa);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return programa;
}
int main(int argc, const char *argv[]) {
    GLFWwindow *window;

    /* Inicializou a biblioteca */
    if (!glfwInit()) {
        return -1;
    }

    /* Cria uma janela em modo de janela e seu contexto OpenGL */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Tornar o contexto da janela atual */
    glfwMakeContextCurrent(window);

    /* glewinit somente depois do contexto*/
    if (glewInit() == GLEW_OK) {
        std::cout << "glew ok" << std::endl;
    } else {
        std::cout << "glew error" << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

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

    /* buffer */
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    /* vertex */
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    /*index buffer object*/
    unsigned int indexB;
    glGenBuffers(1, &indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * 2 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    /* ShaderProgramSrc_S source =
        ParserShader_F("D:/H.R.-DEV/Arquivos-DEV/C++/OpenGL/aula06-shader/Basic.shader"); */
    ShaderProgramSrc_S source = ParserShader_F("aula06-shader/Basic.shader");
    std::cout << "vertex: " << source.VertexSrc << std::endl;
    std::cout << "fragment: " << source.FragmentSrc << std::endl;

    unsigned int shader = CreateShader_F(source.VertexSrc, source.FragmentSrc);
    glUseProgram(shader);

    /* Loop até que o usuário feche a janela */
    while (!glfwWindowShouldClose(window)) {
        /* Renderizar aqui */
        glClear(GL_COLOR_BUFFER_BIT);

        /* draw triangulo */
        // glDrawArrays(GL_TRIANGLES, 0, 6);

        //             gl_t,indices,tipo,null
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        // lindando com errros
        GlCall_F(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

        /* Troca os buffers frontal e traseiro */
        glfwSwapBuffers(window);

        /* Pesquisar e processar eventos */
        glfwPollEvents();
    }

    glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}