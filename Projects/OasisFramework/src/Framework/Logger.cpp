
#include "oapch.h"
#include "Core.h"

#include "Logger.h"

namespace OASFramework {
	std::shared_ptr<spdlog::logger> Logger::m_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::m_ClientLogger;

	void Logger::Initialize() {
		spdlog::set_pattern("%^ [%T] %n: %v%$");

		m_CoreLogger = spdlog::stdout_color_mt("AppCore");
		m_CoreLogger->set_level(spdlog::level::trace);

		m_ClientLogger = spdlog::stdout_color_mt("Client");
		m_ClientLogger->set_level(spdlog::level::trace);
	}
}