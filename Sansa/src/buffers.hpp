#pragma once

#include "pch.hpp"

namespace Sansa
{
    class IndexBuffer{
        private:
            unsigned int counter;
            unsigned int m_Renderer;
        public:
            IndexBuffer();

            void Bind();
            void Unbind();
    };
} // namespace Sansa
