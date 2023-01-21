#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace PalmTree {

	class PALMTREE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Log Errors
#define PT_CORE_TRACE(...)		::PalmTree::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PT_CORE_INFO(...)		::PalmTree::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PT_CORE_WARN(...)		::PalmTree::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PT_CORE_ERROR(...)		::PalmTree::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PT_CORE_FATAL(...)		::PalmTree::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Errors
#define PT_TRACE(...)			::PalmTree::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PT_INFO(...)			::PalmTree::Log::GetClientLogger()->info(__VA_ARGS__)
#define PT_WARN(...)			::PalmTree::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PT_ERROR(...)			::PalmTree::Log::GetClientLogger()->error(__VA_ARGS__)
#define PT_FATAL(...)			::PalmTree::Log::GetClientLogger()->fatal(__VA_ARGS__)
