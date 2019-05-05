#pragma once

#include "IWindow.h"
#include "ApplicationEvents.h"

#include "bpch.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Bandit {

	class BANDIT_API WinWindow : public IWindow
	{
	public:
		struct WindowData
		{
			std::string m_title;
			int m_width, m_height;
			bool m_vsync;

			EventCallback m_eventCallback;
		};


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
			glfwSetWindowUserPointer(m_window, &m_data);

			// set sync on
			glfwSwapInterval(1);

			// set callbacks

			/*glfwSetWindowSizeCallback(m_window, [](GLFWwindow * window, int width, int height)
				{
					TODO: impl
				});*/

			glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) 
				{
					auto& windowData = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
					WindowCloseEvent event;
					windowData.m_eventCallback(event);
				});

		}

		virtual std::unique_ptr<IWindow> Create() override
		{
			return std::make_unique<WinWindow>();
		}

		virtual void SetEventCallback(EventCallback eventCallback) override
		{
			m_data.m_eventCallback = eventCallback;
		}

		virtual GLFWwindow* GetGLFWWindow() const { return m_window; }


	private:
		GLFWwindow* m_window{};
		WindowData m_data;
	};
}