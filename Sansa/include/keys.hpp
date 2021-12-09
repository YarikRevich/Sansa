#pragma once

#include "pch.hpp"

namespace Sansa {
    class Keys{
        private:
            static std::map<const char*, std::function<void()>> s_Keys;
        public:
            static void Handle(const char* key, std::function<void()>);
            inline static const std::map<const char*, std::function<void()>> GetKeys() const { return s_Keys;};
    }
};