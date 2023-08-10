#pragma once

namespace Minecraft {
	class Shader {
	public:
		Shader(const char* vertexShaderSource, const char* fragmentShaderSource);

		void Bind();
	private:
		void _CreateShader(unsigned int* id, const char* source, unsigned int type);

		unsigned int _vs_id;
		unsigned int _fs_id;
		unsigned int _program_id;
	};
}