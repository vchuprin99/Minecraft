#pragma once

#include "shader.h"
#include "vertex_array.h"

namespace Minecraft {
	class Renderer {
	public:
		static int Init();
		
		static void Clear();
		static void Draw(const VertexArray& vertexArray);
	};
}