// #define GLCall() \
// \

#include <memory.h>
#include "spdlog/spdlog.h"


namespace Sansa{
    class Logger {
        private:
            std::shared_ptr<spdlog::logger> s_Logger;
        public:
            static void Init();

            static inline std::shared_ptr<spdlog::logger> GetLogger() {return m_Logger;};
    };
};

#define GL_LOG(...) Sansa::Logger::GetLogger()->error(__VA_ARGS__);
#define LOG_ERROR(...) Sansa::Logger::GetLogger()->error(__VA_ARGS__);
#define LOG_WARN(...) Sansa::Logger::GetLogger()->warn(__VA_ARGS__);
#define LOG_DEBUG(...) Sansa::Logger::GetLogger()->debug(__VA_ARGS__);
