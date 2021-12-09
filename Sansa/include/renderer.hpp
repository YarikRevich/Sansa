#pragma once

#include "pch.hpp"
#include "vao.hpp"
#include "ib.hpp"
#include "log.hpp"
#include "shader.hpp"

namespace Sansa {
	class Renderer {
	public:
		static void Clear();

		static void Update();

		static void Draw(const VAO&, const IndexBuffer&, const Shader&);
	};
};