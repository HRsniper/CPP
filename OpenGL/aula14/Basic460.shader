#shader vertex
#version 460
//#version 460 core

layout(location = 0) in vec4 position;

void main() {
    gl_Position = position;
};

#shader fragment
#version 460
// #version 460 core

layout(location = 0) out vec4 color;

//vec4 buffer
uniform vec4 u_Color;

void main() {

    // color = vec4(0.0, 0.0, 1.0, 1.0);
    color = u_Color;
};