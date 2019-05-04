#pragma once

#include "IWindow.h"

#include "bpch.h"
#include <GLFW/glfw3.h>

namespace Bandit {

	class BANDIT_API WinWindow : public IWindow
	{

	public:
		WinWindow()
		{
			Init();
		}

		~WinWindow()
		{
			if (m_window)
			{
				glfwDestroyWindow(m_window);
			}
		}

		void OnUpdate()
		{
			glfwPollEvents();
			glfwSwapBuffers(m_window);
		}

		void Init()
		{
			if (!glfwInit())
			{
				return;
			}
			m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
			glfwMakeContextCurrent(m_window);
			glfwSetWindowUserPointer(m_window, nullptr);

			// set sync on
			glfwSwapInterval(1);
		}

		virtual std::unique_ptr<IWindow> Create() override
		{
			return std::make_unique<WinWindow>();
		}

	private:
		GLFWwindow* m_window{};
		EventCallback m_eventCallback;
	};
}