#pragma once

#include "Core.h"
#include "Logger.h"
#include "IWindow.h"

namespace Bandit 
{
	class Logger;

	class BANDIT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(IEvent& event);

		auto GetCoreLogger() const { return m_logger->m_coreLogger; }
		auto GetAppLogger() const { return m_logger->m_appLogger; }

	private:
		std::unique_ptr<Logger> m_logger;
		std::unique_ptr<IWindow> m_window;
	};

	// in client
	std::unique_ptr<Application> CreateApplication();

}

