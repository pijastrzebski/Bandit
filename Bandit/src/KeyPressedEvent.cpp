#include "bpch.h"
#include "KeyPressedEvent.h"

namespace Bandit {

	KeyPressedEvent::KeyPressedEvent()
	{
	}


	KeyPressedEvent::~KeyPressedEvent()
	{
	}

	Bandit::IEvent::EventType KeyPressedEvent::GetEventType() const
	{
		return IEvent::KeyPressed;
	}

	std::string KeyPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "Key Pressed Event: Key Code: " << m_keyCode;
		return ss.str();
	}
}
