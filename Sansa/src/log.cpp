#include "log.hpp"

namespace Sansa
{
    void Logger::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_Logger = spdlog::stdout_color_mt("Primis");
        s_Logger->set_level(spdlog::level::trace);
    }
} // namespace Sansa
