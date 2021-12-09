#include "ib.hpp"

Sansa::IndexBuffer::IndexBuffer(const void *data, unsigned int count) : m_Count(count)
{
    GL_LOG(glGenBuffers(1, &m_RendererID));
    Bind();
    GL_LOG(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

Sansa::IndexBuffer::~IndexBuffer()
{
    GL_LOG(glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &m_RendererID));
}

void Sansa::IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void Sansa::IndexBuffer::Unbind() const
{
    GL_LOG(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
