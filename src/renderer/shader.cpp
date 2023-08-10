#include "shader.h"

#include <glad/glad.h>

#include <log.h>

Minecraft::Shader::Shader(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	_CreateShader(&_vs_id, vertexShaderSource, GL_VERTEX_SHADER);
	_CreateShader(&_fs_id, fragmentShaderSource, GL_FRAGMENT_SHADER);

	_program_id = glCreateProgram();
	glAttachShader(_program_id, _vs_id);
	glAttachShader(_program_id, _fs_id);
	glLinkProgram(_program_id);

	int success;
	char infoLog[512];
	glGetProgramiv(_program_id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(_program_id, 512, NULL, infoLog);
		log_err("Shader program error: {}", infoLog);
		return;
	}
	glUseProgram(_program_id);

	glDetachShader(_program_id, _vs_id);
	glDetachShader(_program_id, _fs_id);
	glDeleteShader(_vs_id);
	glDeleteShader(_fs_id);
}

void Minecraft::Shader::Bind()
{
	glUseProgram(_program_id);
}

void Minecraft::Shader::_CreateShader(unsigned int* id, const char* source, unsigned int type)
{
	*id = glCreateShader(type);
	glShaderSource(*id, 1, &source, nullptr);
	glCompileShader(*id);

	int  success;
	char infoLog[512];
	glGetShaderiv(*id, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char* type_string;
		glGetShaderInfoLog(*id, 512, 0, infoLog);
		switch (type)
		{
		case GL_VERTEX_SHADER:
		{
			type_string = (char*)"VERTEX SHADER";
			break;
		}
		case GL_FRAGMENT_SHADER:
		{
			type_string = (char*)"FRAGMENT SHADER";
			break;
		}
		default:
		{
			type_string = (char*)"UNKNOWN SHADER";
			break;
		}
		}
		log_err("{0} compilation error: {1}", type_string, infoLog);
	}
}
