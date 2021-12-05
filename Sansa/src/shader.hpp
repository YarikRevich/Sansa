#pragma once

#include "pch.hpp"

namespace Sansa {
	struct ShaderBundle {
		std::string Fragment;
		std::string Vertex;
	};

	class ShaderLoader {
	public:
		static ShaderBundle LoadShader(const std::string& file);
		static std::vector<ShaderBundle> LoadShadersInDir(const std::string& dir);
	};


	class Shader {
	private:
		unsigned int m_RendererID = 0;

		unsigned int GetUniformLocation(const std::string& name);
		unsigned int CompileShader(unsigned int type, const std::string& src);
		unsigned int CreateShader(const std::string& vs, const std::string& fs);
	public:
		Shader(ShaderBundle);
		~Shader();
	
		void Bind() const;
		void Unbind() const;

		void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	};
};