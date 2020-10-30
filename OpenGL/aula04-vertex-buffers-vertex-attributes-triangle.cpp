// http://docs.gl/
#define GLEW_BUILD
#define GLFW_DLL

#include <GL/glew.h>
#include <GL/glfw3.h>

#include <iostream>

int main(int argc, const char *argv[]) {
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
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

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* draw triangulo */
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}