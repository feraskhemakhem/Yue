#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

#include <memory>

namespace Yue {

	class YUE_API Log
	{
	public:
		static void Init();
		// getters
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// macros for core loggers
#define YUE_CORE_TRACE(...)		::Yue::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define YUE_CORE_INFO(...)		::Yue::Log::GetCoreLogger()->info(__VA_ARGS__)
#define YUE_CORE_WARN(...)		::Yue::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define YUE_CORE_ERROR(...)		::Yue::Log::GetCoreLogger()->error(__VA_ARGS__)
#define YUE_CORE_FATAL(...)		::Yue::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// macros for client loggers
#define YUE_TRACE(...)			::Yue::Log::GetClientLogger()->trace(__VA_ARGS__)
#define YUE_INFO(...)			::Yue::Log::GetClientLogger()->info(__VA_ARGS__)
#define YUE_WARN(...)			::Yue::Log::GetClientLogger()->warn(__VA_ARGS__)
#define YUE_ERROR(...)			::Yue::Log::GetClientLogger()->error(__VA_ARGS__)
#define YUE_FATAL(...)			::Yue::Log::GetClientLogger()->fatal(__VA_ARGS__)