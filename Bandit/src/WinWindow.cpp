#include "bpch.h"
#include "WinWindow.h"

namespace Bandit {

	WinWindow::WinWindow()
	{
		Init();
	}

	WinWindow::~WinWindow()
	{
		if (m_window)
		{
			glfwDestroyWindow(m_window);
		}
	}

	void WinWindow::OnUpdate()
	{
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	void WinWindow::Init()
	{
		if (!glfwInit())
		{
			return;
		}
		m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_data);

		// set sync on
		glfwSwapInterval(1);

		// set callbacks

		/*glfwSetWindowSizeCallback(m_window, [](GLFWwindow * window, int width, int height)
			{
				TODO: impl
			});*/

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow * window)
			{
				auto& windowData = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
				WindowCloseEvent event;
				windowData.m_eventCallback(event);
			});
	}

	std::unique_ptr<IWindow> WinWindow::Create()
	{
		return std::make_unique<WinWindow>();
	}

	void WinWindow::SetEventCallback(EventCallback eventCallback)
	{
		m_data.m_eventCallback = eventCallback;
	}

	GLFWwindow* WinWindow::GetGLFWWindow() const
	{
		return m_window;
	}

}

//void Bandit::WinWindow::Init()
//{
//	
//}
