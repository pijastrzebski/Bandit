#pragma once
#include "IEvent.h"

namespace Bandit {

	class WindowCloseEvent : public IEvent
	{
	public:
		WindowCloseEvent(unsigned int width, unsigned int height);
		virtual ~WindowCloseEvent();

		virtual EventType GetEventType() const override;
		virtual std::string ToString() const override;

	private:
		unsigned int m_width;
		unsigned int m_height;

	};
}
