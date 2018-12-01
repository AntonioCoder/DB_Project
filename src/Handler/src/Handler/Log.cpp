#include "WNDpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

_HANDLER_START
std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

void Log::Init()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");
	s_CoreLogger = spdlog::stdout_color_mt("HANDLER");
	spdlog::set_level(spdlog::level::trace);

	s_ClientLogger = spdlog::stdout_color_mt("CLIENT");
	spdlog::set_level(spdlog::level::trace);
}
_HANDLER_END