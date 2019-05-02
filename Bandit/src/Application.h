#pragma once

#include "Core.h"
#include "Logger.h"
#include <memory>

namespace Bandit 
{
	class Logger;

	class BANDIT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		auto GetCoreLogger() const { return m_logger->m_coreLogger; }
		auto GetAppLogger() const { return m_logger->m_appLogger; }

	private:
		std::unique_ptr<Bandit::Logger> m_logger;
	};

	// in client
	std::unique_ptr<Application> CreateApplication();

}

