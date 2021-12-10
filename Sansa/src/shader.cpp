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
				continue;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
				continue;
			}
		}

		switch (type)
		{
		case ShaderType::VERTEX:
			vertexShader << line << "\n";
			break;
		case ShaderType::FRAGMENT:
			fragmentShader << line << "\n";
			break;
		case ShaderType::NONE:
			continue;
		};
	}

	return {fragmentShader.str(), vertexShader.str()};
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

	int status;
	GL_LOG(glGetShaderiv(id, GL_COMPILE_STATUS, &status));
	if (!status)
	{
		int length = 0;
		GL_LOG(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
		if (length)
		{
			std::string log;
			GL_LOG(glGetShaderInfoLog(id, length, nullptr, &log[0]));
			LOG_ERROR(log.c_str(), (type == GL_VERTEX_SHADER ? "vertex shader" : "fragment shader"));
		}
		GL_LOG(glDeleteShader(id));
	}

	return id;
}

unsigned int Sansa::Shader::CreateShader(const std::string &vs, const std::string &fs)
{
	GL_LOG(unsigned int program = glCreateProgram());
	unsigned int idvs = CompileShader(GL_VERTEX_SHADER, vs);
	unsigned int idfs = CompileShader(GL_FRAGMENT_SHADER, fs);

	GL_LOG(glAttachShader(program, idvs));
	GL_LOG(glAttachShader(program, idfs));

	GL_LOG(glLinkProgram(program));
	GL_LOG(glValidateProgram(program));

	GL_LOG(glDeleteShader(idvs));
	GL_LOG(glDeleteShader(idfs));

	return program;
}

Sansa::Shader::Shader(ShaderBundle bundle)
{
	this->m_RendererID = CreateShader(bundle.Vertex, bundle.Fragment);
	Bind();
}

Sansa::Shader::~Shader()
{

	GL_LOG(glDeleteProgram(m_RendererID));
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
	GL_LOG(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}

void Sansa::Shader::SetUniform1i(const std::string& name, int v0){
	GL_LOG(glUniform1i(GetUniformLocation(name), v0));
	int r;
	glGetUniformiv(m_RendererID, 0, &r);
	std::cout << "name " << name << " " <<  r << std::endl;
}
