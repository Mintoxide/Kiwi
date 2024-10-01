#include "Common.h"

#include <iostream>

#include "Window.h"
#include "Shader.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
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
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
       -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f
    };

    auto vbo = VertexBufferObject();
    vbo.SubmitVertices(&vertices);

    auto vao = VertexArrayObject();
    vao.MakeCurrent();
    vao.CreateAttributes({ 3, 3 });
    
    while (!window.ShouldClose())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        vbo.RenderVertices();
        window.Update();
    }


    glfwTerminate();
    return 0;
}