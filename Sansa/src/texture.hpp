#pragma once

#include "pch.hpp"

namespace Sansa{
    class Texture{
    private:
        unsigned int m_RendererID;
    public:
        Texture();
        void Bind() const;
        void Unbind() const;
    };
};