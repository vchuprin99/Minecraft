#include "vertex_array.h"

#include <glad/glad.h>

#include <log.h>

namespace Minecraft {
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_id);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_id);
	}

	void VertexArray::addVertexBuffer(const VertexBuffer& vertexBuffer)
	{
		bind();
		for (const BufferElement& currentElement : vertexBuffer.getLayout().getElements()) {
			glEnableVertexAttribArray(m_elementsCount);
			glVertexAttribPointer(
				m_elementsCount,
				static_cast<GLint>(currentElement.componentCount),
				currentElement.componentType,
				false,
				static_cast<GLsizei>(vertexBuffer.getLayout().getStride()),
				reinterpret_cast<const void*>(currentElement.offset)
			);
			++m_elementsCount;
		}
	}

	void VertexArray::setIndexBuffer(const IndexBuffer& indexBuffer)
	{
		bind();
		indexBuffer.bind();
		m_indicesCount = indexBuffer.getCount();
	}

	void VertexArray::bind() const
	{
		glBindVertexArray(m_id);
	}

	void VertexArray::unbind()
	{
		glBindVertexArray(0);
	}
}