// http://docs.gl/
#define GLEW_BUILD
#define GLFW_DLL

#include <GL/glew.h>
#include <GL/glfw3.h>

#include <cstdlib>
#include <iostream>

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
    float positions[6] = {-0.5f, -0.5f, //
                          0.0f,  0.5f,  //
                          0.5f,  -0.5f};
    std::cout << positions << std::endl;

    /* buffer */
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    /* vertex */
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    std::string vertexShader = "#version 330 core \n"
                               "\n layout(location = 0) in vec4 position; \n"
                               "\n"
                               "void main() { \n"
                               "    gl_Position = position; \n"
                               "} \n";

    std::string fragmentShader = "#version 330 core \n"
                                 "\n layout(location = 0) out vec4 color; \n"
                                 "\n"
                                 "void main() { \n"
                                 "    color = vec4(1.0, 0.0, 0.0, 1.0); \n"
                                 "} \n";

    unsigned int shader = CreateShader_F(vertexShader, fragmentShader);
    glUseProgram(shader);

    /* Loop até que o usuário feche a janela */
    while (!glfwWindowShouldClose(window)) {
        /* Renderizar aqui */
        glClear(GL_COLOR_BUFFER_BIT);

        /* draw triangulo */
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Troca os buffers frontal e traseiro */
        glfwSwapBuffers(window);

        /* Pesquisar e processar eventos */
        glfwPollEvents();
    }

    glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}