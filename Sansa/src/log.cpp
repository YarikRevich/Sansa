#include "log.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Sansa
{
    std::shared_ptr<spdlog::logger> Logger::s_Logger = nullptr;
    void Logger::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_Logger = spdlog::stdout_color_mt("Primis");
        s_Logger->set_level(spdlog::level::trace);
    }
} // namespace Sansa
