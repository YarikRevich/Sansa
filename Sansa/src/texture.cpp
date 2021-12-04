#include "texture.hpp"

Sansa::Texture::Texture()
{
	glGenTextures(1, &m_RendererID);
}

void Sansa::Texture::Bind() const
{
}

void Sansa::Texture::Unbind() const
{
}