#include "texture.hpp"

#include "stb_image/stb_image.h"

Sansa::Texture::Texture(const std::string& file) : m_FilePath(file)
{
	GL_LOG(glGenTextures(1, &m_RendererID));
	Bind();

	stbi_set_flip_vertically_on_load(true); 
	m_LocalBuffer = stbi_load(file.c_str(), &m_Width, &m_Height, &m_BPP, 4);

	GL_LOG(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GL_LOG(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));	
	GL_LOG(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));	
	GL_LOG(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

	GL_LOG(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));	
	
	Unbind();

	if (m_LocalBuffer){
		stbi_image_free(m_LocalBuffer);
	}
}

void Sansa::Texture::Bind(unsigned int slot) const
	GL_LOG(glActiveTexture(GL_TEXTURE0 + slot));
	GL_LOG(glBindTexture(GL_TEXTURE_2D, m_RendererID));
}

void Sansa::Texture::Unbind() const
{
	GL_LOG(glBindTexture(GL_TEXTURE_2D, 0));
}