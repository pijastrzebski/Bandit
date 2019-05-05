#pragma once

#include "IWindow.h"

#include "bpch.h"
#include <GL/glew.h>
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

		void OnUpdate() override
		{
			glfwSwapBuffers(m_window);
			glfwPollEvents();
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

			// set callbacks
			/*glfwSetWindowSizeCallback(m_window, [](GLFWwindow * window, int width, int height)
				{
					auto userData = glfwGetWindowUserPointer(window);


				});*/
			glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) 
				{
					auto userData = glfwGetWindowUserPointer(window);
					WindowCloseEvent event;
				});

		}

		virtual std::unique_ptr<IWindow> Create() override
		{
			return std::make_unique<WinWindow>();
		}

		virtual void SetEventCallback(EventCallback eventCallback) override
		{
			m_eventCallback = eventCallback;
		}

		virtual GLFWwindow* GetGLFWWindow() const { return m_window; }


	private:
		GLFWwindow* m_window{};
		EventCallback m_eventCallback;
	};
}