 #pragma once

#include "pch.hpp"

namespace Sansa{
    class VBO{
        private:
            int m_RendererID;
        public:
            VBO();
            ~VBO();

            void Bind() const;
            void Unbind() const;
    };
};