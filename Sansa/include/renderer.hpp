#pragma once

#include "pch.hpp"
#include "vao.hpp"
#include "ib.hpp"
#include "log.hpp"
#include "shader.hpp"

namespace Sansa {
	class Renderer {
	private:
		static std::function<void()> uniforms_c;
	public:
		static void Clear();

		static void Update();

		static void SetUniforms(std::function<void()>); 

		static void Draw(const VAO&, const IndexBuffer&, const Shader&);
	};
};