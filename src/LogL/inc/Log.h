#pragma once
#include "LOGpch.h"
#include "LOGmacros.h"

_LOG_START
class LOG_API Log
{
public:
	static void Init();
	
	inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
	inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

protected:

private:
	static std::shared_ptr<spdlog::logger> s_CoreLogger;
	static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

_LOG_END

// Core log macros
#define LOG_CORE_TRACE(...)		_LOG Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)		_LOG Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)		_LOG Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)		_LOG Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_FATAL(...)		_LOG Log::GetCoreLogger()->fatal(__VA_ARGS__)
								 
// Client log macros
#define LOG_TRACE(...)			 _LOG Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)			 _LOG Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)			 _LOG Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)			 _LOG Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...)			 _LOG Log::GetClientLogger()->fatal(__VA_ARGS__)
