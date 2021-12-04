#include "vbo.hpp"
#include "log.hpp"

Sansa::VBO::VBO()
{
	glGenBuffers(1, &m_RendererID)
}

Sansa::VBO::~VBO()
{
	glDeleteBuffers(1, &m_RendererID);
}

void Sansa::VBO::Bind() const
{
	glBindBuffer(GL_BUFFER, m_RendererID)
}

void Sansa::VBO::Unbind() const
{
	glBindBuffer(GL_BUFFER, 0)
}
