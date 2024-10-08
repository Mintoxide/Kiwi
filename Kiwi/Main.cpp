#include "Common.h"

#include <iostream>

#include "Window.h"
#include "Shader.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElementBufferObject.h"
#include "Signal.h"

using namespace Kiwi;

int main(void)
{

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto window = GLWindow(800, 600, "Kiwi Application");

    auto shaders = ShaderProgram({
        Shader(ShaderType::Vertex, Shader::FromFile("Basic.vert").data()),
        Shader(ShaderType::Fragment, Shader::FromFile("Basic.frag").data())});
    shaders.Use();

    auto vertices = std::vector<float>{
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };

    auto indices = std::vector<uint32>{
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    auto vbo = VertexBufferObject();
    vbo.SubmitVertices(&vertices);

    auto vao = VertexArrayObject();
    vao.MakeCurrent();
    vao.CreateAttributes({ 3 });

    auto ebo = ElementBufferObject();
    ebo.SubmitIndices(&indices);
    
    while (!window.ShouldClose())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        vbo.RenderVertices(&ebo);
        window.Update();
    }


    glfwTerminate();
    return 0;
}