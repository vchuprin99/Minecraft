#include "application.h"
#include "renderer/renderer.h"

#include <log.h>

#include <glad/glad.h>

std::unique_ptr<Minecraft::VertexBuffer> vertex_buffer;
std::unique_ptr<Minecraft::IndexBuffer> index_buffer;
std::unique_ptr<Minecraft::VertexArray> vertex_array;
std::unique_ptr<Minecraft::Shader> shader;

class MinecraftApp : public Minecraft::Application {
	virtual void OnUserStart() override {
		Minecraft::Renderer::Init();

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		float points[] = {
			0.5, 0.5, 0,
			-0.5, 0.5, 0,
			-0.5, -0.5, 0,
			0.5, -0.5, 0,
		};
		unsigned int indicies[] = {
			0, 1, 2,
			0, 2, 3
		};

		const char* vertexShader = R"(
			#version 330

			in vec3 in_pos;

			void main(){
				gl_Position = vec4(in_pos, 1);
			}
		)";
		const char* fragmentShader = R"(
			#version 330

			out vec4 FragColor;

			void main(){
				FragColor = vec4(1, 0, 0, 1);
			}
		)";
		Minecraft::BufferLayout layout = {
			Minecraft::ShaderDataType::Float3,

		};
		vertex_buffer = std::make_unique<Minecraft::VertexBuffer>(points, sizeof(points), layout);
		index_buffer = std::make_unique<Minecraft::IndexBuffer>(indicies, sizeof(indicies));
		vertex_array = std::make_unique<Minecraft::VertexArray>();
		vertex_array->addVertexBuffer(*vertex_buffer);
		vertex_array->setIndexBuffer(*index_buffer);

		shader = std::make_unique<Minecraft::Shader>(vertexShader, fragmentShader);
		shader->Bind();
	}
	virtual void OnUserUpdate() override {
		Minecraft::Renderer::Clear();

		Minecraft::Renderer::Draw(*vertex_array);

	}
};

int main() {
	
	auto app = std::make_unique<MinecraftApp>();
	app->Construct({ 1280, 720, "Minecraft", false, false });
	app->Start();

	return 0;
}