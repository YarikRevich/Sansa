#include "vao.hpp"
#include "log.hpp"

Sansa::VAO::VAO()
{
	glGenVertexArrays(1, &m_RendererID);
}

Sansa::VAO::~VAO()
{
	glDeleteVertexArrays(1, &m_RendererID);  
}

void Sansa::VAO::AddBuffer(const VBO& vb, const VBOLayout& layout)
{
	Bind();  
	vb.Bind();
	auto elements = layout.GetElements();
	unsigned int offset = 0;
	for (int i = 0; i < elements.size(); ++i) {
		auto element = elements[i];
		GL_LOG(glEnableVertexAttribArray(0));
		GL_LOG(glVertexAttribPointer(0, element.count, element.type, element.normilized, layout.GetStride(), (const void*)offset));
		offset += element.count;
	}
}

void Sansa::VAO::Bind() const
{
	glBindVertexArray(m_RendererID);
}

void Sansa::VAO::Unbind() const
{
	glBindVertexArray(0);
}
