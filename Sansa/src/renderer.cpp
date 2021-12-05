#include "renderer.hpp"


void Sansa::Renderer::Clear()
{
	GL_LOG(glClear(GL_COLOR_BUFFER_BIT));
}

void Sansa::Renderer::Draw(const VAO& vao, const IndexBuffer& ib, const Shader& shader)
{
	Clear();

	shader.Bind();
	vao.Bind();
	ib.Bind();
	
	GL_LOG(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
