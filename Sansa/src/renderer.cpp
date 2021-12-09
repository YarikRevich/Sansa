#include "renderer.hpp"


void Sansa::Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Sansa::Renderer::Update() {
	// Sansa::Keys::GetKeys()
}

void Sansa::Renderer::Draw(const VAO& vao, const IndexBuffer& ib, const Shader& shader)
{
	shader.Bind();
	vao.Bind();
	ib.Bind();

	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}
