#pragma once

#include "pch.hpp"

namespace Sansa{
    class OBJLoader{
        public:
            OBJLoader(const std::string&, std::vector<glm::vec3>&, std::vector<int>&);
    };
};