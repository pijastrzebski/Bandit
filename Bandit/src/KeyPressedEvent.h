#pragma once
#include "IEvent.h"

namespace Bandit {

	class KeyPressedEvent : public IEvent
	{
	public:
		KeyPressedEvent();
		virtual ~KeyPressedEvent();

		virtual EventType GetEventType() const override;
		virtual std::string ToString() const override;

	private:
		int m_keyCode{};
	};
}


