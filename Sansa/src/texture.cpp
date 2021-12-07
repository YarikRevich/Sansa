#include "texture.hpp"

Sansa::Texture::Texture()
{
	glGenTextures(1, &m_RendererID);
}

void Sansa::Texture::Bind() const
{
	// #ifdef VULKAN_SANSA
	
	// #elif defined(OPENGL_SANSA)

	// #endif
}

void Sansa::Texture::Unbind() const
{
}