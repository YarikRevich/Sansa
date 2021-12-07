 #pragma once

#include "pch.hpp"

namespace Sansa{
    class VBO{
        private:
            unsigned int m_RendererID;
        public:
            VBO(const void*, unsigned int);
            ~VBO();

            void Bind() const;
            void Unbind() const;
    };
};