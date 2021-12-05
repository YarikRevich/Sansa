#pragma once

#include "pch.hpp"

namespace Sansa
{
    class IndexBuffer{
        private:
            unsigned int m_Count;
            unsigned int m_Renderer;
        public:
            IndexBuffer();

            void Bind() const;
            void Unbind() const;

            inline unsigned int GetCount() { return m_Count; };
    };
} // namespace Sansa
