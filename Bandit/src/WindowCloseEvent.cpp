#include "bpch.h"
#include "WindowCloseEvent.h"

namespace Bandit {

	WindowCloseEvent::WindowCloseEvent(unsigned int width, unsigned int height) :
		m_width(width),
		m_height(height)
	{
	}


	WindowCloseEvent::~WindowCloseEvent()
	{
	}

	Bandit::IEvent::EventType WindowCloseEvent::GetEventType() const
	{
		return IEvent::WindowClose;
	}

	std::string WindowCloseEvent::ToString() const
	{
		std::stringstream ss;
		ss << "Window Close Event: " << m_width << " x " << m_height;
		return ss.str();
	}
}
