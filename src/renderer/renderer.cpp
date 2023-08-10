#define RENDERER_IMP
#include "renderer.h"

#include <glad/glad.h>

#include <log.h>


int Minecraft::Renderer::Init()
{
    int ret = gladLoadGL();
    if (ret != 1) {
        log_err("OpenGL initialization error");
    }
    return ret;
}

void Minecraft::Renderer::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Minecraft::Renderer::Draw(const VertexArray& vertexArray)
{
    glDrawElements(GL_TRIANGLES, vertexArray.getIndicesCount(), GL_UNSIGNED_INT, nullptr);
}
