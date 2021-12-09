#include "objloader.hpp"

Sansa::OBJLoader::OBJLoader(const std::string &file, std::vector<glm::vec3> &vertecies, std::vector<int> &indecies)
{
    std::ifstream f(file);
    std::stringstream ss;
    // ss << f.rdbuf();

    // std::vector<glm::vec3> vertex_position_indecies, vertex_texcoord_indecies, vertex_normal_indecies;

    glm::vec3 vertex;
    glm::vec3 index;

    GLint temp_glint;

    std::string prefix;

    std::string line;
    while (std::getline(f, line))
    {        
        ss.clear();
        ss.str(line);
        ss >> prefix;

        if (prefix == "v")
        {
            ss >> vertex.x >> vertex.y >> vertex.z;
            vertecies.push_back({vertex});
        }
        else if (prefix == "vt")
        {
            // ss >> index.x >> index.y >> index.z;
            // indecies.push_back({index});
        }
        else if (prefix == "f")
        {
            int counter = 0;
            while (ss >> temp_glint)
            {
                if (counter == 0)
                {
                    indecies.push_back(temp_glint);
                    // vertex_position_indecies.push_back(temp_glint);
                }
                else if (counter == 1)
                {
                    // vertex_texcoord_indecies.push_back(temp_glint);
                }
                else if (counter == 2)
                {
                    // vertex_normal_indecies.push_back(temp_glint);
                }

                if (ss.peek() == '/')
                {
                    ++counter;
                    ss.ignore(1, '/');
                }
                else if (ss.peek() == ' ')
                {
                    ++counter;
                    ss.ignore(1, ' ');
                }

                if (counter > 2)
                {
                    counter = 0;
                }
            };

            // vertecies.resize(vertex_position_indecies.size());

            // for (int i = 0; i < vertex_position_indecies.size(); ++i){

            // }
        }

        
    }
    std::cout << "Number of vertices: " << vertecies.size() << "\n";
    std::cout << "Number of indices: " << indecies.size() << "\n";
}
