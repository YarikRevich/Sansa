#include "shader.hpp"

Sansa::ShaderBundle Sansa::ShaderLoader::LoadShader(const std::string &file)
{
	std::ifstream f(file);

	std::stringstream s;

	s << f.rdbuf();

	enum class ShaderType
	{
		NONE = 0,
		VERTEX = 1,
		FRAGMENT = 2,
	};

	ShaderType type;

	std::stringstream vertexShader;
	std::stringstream fragmentShader;

	std::string line;
	while (std::getline(s, line))
	{

		if (line.find("#type") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}

		switch (type)
		{
		case ShaderType::VERTEX:
			vertexShader << line;
		case ShaderType::FRAGMENT:
			fragmentShader << line;
		case ShaderType::NONE:
			continue;
		};
	}

	return {vertexShader.str(), fragmentShader.str()};
}

std::vector<Sansa::ShaderBundle> Sansa::ShaderLoader::LoadShadersInDir(const std::string &dir)
{
	std::vector<Sansa::ShaderBundle> b;

	using std::filesystem::directory_iterator;

	for (const auto &file : directory_iterator(dir))
	{
		b.push_back(LoadShader(file.path()));
	};

	return b;
}

unsigned int Sansa::Shader::GetUniformLocation(const std::string &name)
{
	GL_LOG(return glGetUniformLocation(m_RendererID, name.c_str()));
}

unsigned int Sansa::Shader::CompileShader(unsigned int type, const std::string &src)
{
	GL_LOG(unsigned int id = glCreateShader(type));
	const char *s = src.c_str();
	GL_LOG(glShaderSource(id, 1, &s, nullptr));
	GL_LOG(glCompileShader(id));
	return id;
}

unsigned int Sansa::Shader::CreateShader(const std::string &vs, const std::string &fs)
{

	unsigned int program = glCreateProgram();
	unsigned int idvs = CompileShader(GL_VERTEX_SHADER, vs);
	unsigned int idfs = CompileShader(GL_FRAGMENT_SHADER, fs);

	glAttachShader(program, idvs);
	glAttachShader(program, idfs);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(idvs);
	glDeleteShader(idfs);

	return program;
}

Sansa::Shader::Shader(ShaderBundle bundle)
{
	m_RendererID = CreateShader(bundle.Vertex, bundle.Fragment);
}

Sansa::Shader::~Shader()
{
	glDeleteProgram(m_RendererID);
}

void Sansa::Shader::Bind() const
{
	GL_LOG(glUseProgram(m_RendererID));
}

void Sansa::Shader::Unbind() const
{
	GL_LOG(glUseProgram(0));
}

void Sansa::Shader::SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3)
{
	auto location = GetUniformLocation(name);
	glUniform4f(location, v0, v1, v2, v3);
}
