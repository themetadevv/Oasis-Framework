#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace OASFramework {
	class OAPI Logger {
	public:
		static void Initialize();

		static std::shared_ptr<spdlog::logger> GetCoreLogger() {
			return m_CoreLogger;
		}

		static std::shared_ptr<spdlog::logger> GetClientLogger() {
			return m_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_ClientLogger;
	};
}

#define OA_CORE_ERROR(...)  ::OASFramework::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define OA_CORE_WARN(...)   ::OASFramework::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define OA_CORE_INFO(...)   ::OASFramework::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define OA_CORE_TRACE(...)  ::OASFramework::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define OA_CORE_FATAL(...)  ::OASFramework::Logger::GetCoreLogger()->fatal(__VA_ARGS__)

#define OA_CLIENT_ERROR(...)  ::OASFramework::Logger::GetClientLogger()->error(__VA_ARGS__)
#define OA_CLIENT_WARN(...)   ::OASFramework::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define OA_CLIENT_INFO(...)   ::OASFramework::Logger::GetClientLogger()->info(__VA_ARGS__)
#define OA_CLIENT_TRACE(...)  ::OASFramework::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define OA_CLIENT_FATAL(...)  ::OASFramework::Logger::GetClientLogger()->fatal(__VA_ARGS__)