#include <spdlog/spdlog.h>

#define log_info(...) spdlog::info(__VA_ARGS__)
#define log_warn(...) spdlog::warn(__VA_ARGS__)
#define log_crit(...) spdlog::critical(__VA_ARGS__)
#define log_err(...) spdlog::error(__VA_ARGS__)