#pragma once

#include "IWindow.h"
#include "ApplicationEvents.h"

//#include "bpch.h"
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


		WinWindow();
		~WinWindow();

		void OnUpdate() override;
		void Init();
		virtual std::unique_ptr<IWindow> Create() override;
		virtual void SetEventCallback(EventCallback eventCallback) override;
		virtual GLFWwindow* GetGLFWWindow() const;


	private:
		GLFWwindow* m_window{};
		WindowData m_data;
	};
}