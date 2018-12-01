#pragma once

#include <memory>

#include "macros.h"
#include "spdlog/spdlog.h"

_HANDLER_START
class HANDLER_API Log
{
public:
	static void Init();
	
	inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
	inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

private:
	static std::shared_ptr<spdlog::logger> s_CoreLogger;
	static std::shared_ptr<spdlog::logger> s_ClientLogger;
};
_HANDLER_END

// Core log macros
#define H_CORE_TRACE(...)		_HANDLER Log::GetCoreLogger()->trace(__VA_ARGS__)
#define H_CORE_INFO(...)		_HANDLER Log::GetCoreLogger()->info(__VA_ARGS__)
#define H_CORE_WARN(...)		_HANDLER Log::GetCoreLogger()->warn(__VA_ARGS__)
#define H_CORE_ERROR(...)		_HANDLER Log::GetCoreLogger()->error(__VA_ARGS__)
#define H_CORE_FATAL(...)		_HANDLER Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define H_TRACE(...)			_HANDLER Log::GetClientLogger()->trace(__VA_ARGS__)
#define H_INFO(...)				_HANDLER Log::GetClientLogger()->info(__VA_ARGS__)
#define H_WARN(...)				_HANDLER Log::GetClientLogger()->warn(__VA_ARGS__)
#define H_ERROR(...)			_HANDLER Log::GetClientLogger()->error(__VA_ARGS__)
#define H_FATAL(...)			_HANDLER Log::GetClientLogger()->fatal(__VA_ARGS__)
