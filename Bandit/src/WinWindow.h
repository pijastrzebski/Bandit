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

		void Init()
		{
			if (!glfwInit())
			{
				return;
			}
		}

		virtual std::unique_ptr<IWindow> Create() override
		{
			return std::make_unique<WinWindow>();
		}

	private:
		GLFWwindow* m_window;
		EventCallback m_eventCallback;
	};
}