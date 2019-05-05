#pragma once
#include "IEvent.h"

namespace Bandit {

	class BANDIT_API KeyPressedEvent : public IEvent
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


