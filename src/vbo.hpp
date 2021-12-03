#pragma once

namespace Sansa{
    class VBO{
        private:
            int m_RendererID;
        public:
            VBO(const int rendererID); 
            ~VBO();

            void Bind();
            void Unbind();
    };
    
};