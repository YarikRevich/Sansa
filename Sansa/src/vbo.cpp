#include "vbo.hpp"
#include "log.hpp"

Sansa::VBO::VBO(const void* data, unsigned int size)
{
	
	GL_LOG(glGenBuffers(1, &m_RendererID));
	GL_LOG(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	GL_LOG(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

Sansa::VBO::~VBO()
{
	GL_LOG(glDeleteBuffers(1, &m_RendererID));
}

void Sansa::VBO::Bind() const
{
	GL_LOG(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void Sansa::VBO::Unbind() const
{
	GL_LOG(glBindBuffer(GL_BUFFER, 0));
}
