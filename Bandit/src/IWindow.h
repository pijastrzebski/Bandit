#pragma once

#include "bpch.h"

#include "Core.h"
#include "IEvent.h"

struct GLFWwindow;

namespace Bandit {
	
	class BANDIT_API IWindow
	{
	public:
		using EventCallback = std::function<void(IEvent&)>;

		IWindow(std::string title = "Bandit Engine", int width = 1280,
			                                         int height = 720) :
			m_title(title),
			m_width(width),
			m_height(height) {}
		~IWindow() {}

		virtual std::unique_ptr<IWindow> Create() = 0;
		virtual void SetEventCallback(EventCallback eventCallback) = 0;
		virtual void OnUpdate() = 0;
		virtual GLFWwindow* GetGLFWWindow() const = 0;

	protected:
		std::string m_title;
		int m_width;
		int m_height;
	};


}