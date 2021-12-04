#pragma once

#include "vbolayout.hpp"
#include "vbo.hpp"

namespace Sansa {
	class VAO {
	private:
		unsigned int m_RendererID;
	public:
		VAO();
		~VAO();
			
		void AddBuffer(const VBO&, const VBOLayout&);

		void Bind() const;
		void Unbind() const;
	};
};