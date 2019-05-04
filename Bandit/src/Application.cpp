#include "bpch.h"

#include "Application.h"
#include "ApplicationEvents.h"
#include "WinWindow.h"

namespace Bandit {

	Application::Application() :
		m_logger(std::make_unique<Bandit::Logger>())
	{
		GetCoreLogger()->warn("Initialize Core Logger!");
		GetAppLogger()->info("Initialize Client Logger!");
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WinWindow window;
		WindowCloseEvent e(800, 600);
		GetAppLogger()->info(e.ToString()); 

		//TODO: do something with this event


		while (true);
	}
}

