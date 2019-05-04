#include "bpch.h"

#include "Application.h"
#include "ApplicationEvents.h"
#include "WinWindow.h"

namespace Bandit {

	Application::Application() :
		m_logger(std::make_unique<Logger>()),
		m_window(std::make_unique<WinWindow>())
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowCloseEvent e(800, 600);
		GetAppLogger()->info(e.ToString()); 

		//TODO: do something with this event


		while (true);
	}
}

