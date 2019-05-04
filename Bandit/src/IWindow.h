#pragma once

#include "bpch.h"

#include "Core.h"
#include "IEvent.h"

namespace Bandit {

	class BANDIT_API IWindow
	{
	public:
		using EventCallback = std::function<void(IEvent&)>;

		IWindow(std::string title = "Bandit Engine", unsigned int width = 1280,
			                                        unsigned int height = 720) :
			m_title(title),
			m_width(width),
			m_height(height) {}
		~IWindow() {}

		virtual std::unique_ptr<IWindow> Create() = 0;

	private:
		std::string m_title;
		unsigned int m_width;
		unsigned int m_height;
	};

}