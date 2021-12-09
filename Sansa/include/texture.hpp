#pragma once

#include "pch.hpp"

namespace Sansa{
    class Texture{
    private:
        unsigned int m_RendererID;
        std::string m_FilePath;
        unsigned char* m_LocalBuffer;
        int m_Width = 0, m_Height = 0, m_BPP = 0 ;
    public:
        Texture(const std::string&);
        ~Texture();

        void Bind(unsigned int slot = 0) const;
        void Unbind() const;
    };
};