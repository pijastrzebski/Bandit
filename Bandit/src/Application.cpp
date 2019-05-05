#include "bpch.h"

#include "Application.h"
#include "ApplicationEvents.h"
#include "EventDispatcher.h"
#include "WinWindow.h"

namespace Bandit {

	Application::Application() :
		m_logger(std::make_unique<Logger>()),
		m_window(std::make_unique<WinWindow>()),
		m_running(true)
	{
		m_window->SetEventCallback([this](IEvent& event) {this->OnEvent(event); });
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_running)
		{
			glClearColor(1, 0, 1, 1); // set pink window
			glClear(GL_COLOR_BUFFER_BIT);
			m_window->OnUpdate();
		}
	}

	void Application::OnEvent(IEvent& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch([&]() { return OnWindowClose(event); });

		GetAppLogger()->info("{}", event);
	}

	bool Application::OnWindowClose(IEvent& event)
	{
		m_running = false;
		return true;
	}

}

