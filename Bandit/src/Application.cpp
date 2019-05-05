#include "bpch.h"

#include "Application.h"
#include "ApplicationEvents.h"
#include "WinWindow.h"

namespace Bandit {

	Application::Application() :
		m_logger(std::make_unique<Logger>()),
		m_window(std::make_unique<WinWindow>())
	{
		m_window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowCloseEvent e(800, 600);
		GetAppLogger()->info(e.ToString()); 

		//TODO: do something with this event


		while (!glfwWindowShouldClose(m_window->GetGLFWWindow()))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			m_window->OnUpdate();
		}
	}

	void Application::OnEvent(IEvent& event)
	{
		GetAppLogger()->info("{}", event);
	}

}

