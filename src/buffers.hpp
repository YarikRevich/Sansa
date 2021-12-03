#pragma once

namespace Sansa
{
    class IndexBuffer{
        private:
            int counter;
            int m_Renderer;
        public:
            IndexBuffer();

            void Bind();
            void Unbind();
    };
} // namespace Sansa
