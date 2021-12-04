#include "buffers.hpp"

Sansa::IndexBuffer::IndexBuffer()
{
	glGenBuffers(1, &m_Renderer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Renderer);
}

void Sansa::IndexBuffer::Bind()
{
}

void Sansa::IndexBuffer::Unbind()
{
}
