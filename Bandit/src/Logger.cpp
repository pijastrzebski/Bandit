#include "Logger.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Bandit {

	Logger::Logger()
	{
		Init();
	}


	void Logger::Init()
	{
		spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

		m_coreLogger = spdlog::stdout_color_mt("BANDIT");
		m_coreLogger->set_level(spdlog::level::trace);

		m_appLogger = spdlog::stderr_color_mt("APP");
		m_appLogger->set_level(spdlog::level::trace);

	}

	Logger::~Logger()
	{
	}

}