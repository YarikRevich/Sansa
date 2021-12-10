#include "renderer.hpp"

std::function<void()> Sansa::Renderer::uniforms_c = nullptr;


void Sansa::Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Sansa::Renderer::Update() {
	// Sansa::Keys::GetKeys()
}

void Sansa::Renderer::SetUniforms(std::function<void()> c){
	uniforms_c = c;
}; 

void Sansa::Renderer::Draw(const VAO& vao, const IndexBuffer& ib, const Shader& shader)
{
	// shader.Bind();

	// uniforms_c();

	vao.Bind();
	ib.Bind();

	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}
