#pragma once

#include <memory.h>
#include "spdlog/spdlog.h"

#include "pch.hpp"

namespace Sansa{
    class Logger {
        private:
            static std::shared_ptr<spdlog::logger> s_Logger;
        public:
            static void Init();

            static inline std::shared_ptr<spdlog::logger> GetLogger() {return s_Logger;};
    };
};

#define GL_LOG(x) \
    GLClearError();\
    x;\
    GLLogCall(#x);

static void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
};


#define LOG_ERROR(...) Sansa::Logger::GetLogger()->error(__VA_ARGS__);
#define LOG_WARN(...) Sansa::Logger::GetLogger()->warn(__VA_ARGS__);
#define LOG_DEBUG(...) Sansa::Logger::GetLogger()->debug(__VA_ARGS__);

static void GLLogCall(std::string functionName) {
    while (GLenum error = glGetError()) {
        std::cout << "GL_ERROR " << error << " Function " << functionName << " " << "File: " << __FILE__ << " " << "Line: " << __LINE__ << " " << std::endl;
    }
};

