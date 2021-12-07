#pragma once

#include "pch.hpp"
#include "log.hpp"

namespace Sansa
{
    class IndexBuffer{
        private:
            unsigned int m_Count;
            unsigned int m_RendererID;
        public:
            IndexBuffer(const void*, unsigned int);
            ~IndexBuffer();

            void Bind() const;
            void Unbind() const;

            inline unsigned int GetCount() const { return m_Count; };
    };
} // namespace Sansa