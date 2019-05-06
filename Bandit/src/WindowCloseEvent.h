#pragma warning( disable: 4244 4251 ) // suppress spdlog compiler warnings 

#pragma once
#include "IEvent.h"
#include "Logger.h"

namespace Bandit {

	class BANDIT_API WindowCloseEvent : public IEvent
	{
	public:
		WindowCloseEvent() = default;
		WindowCloseEvent(unsigned int width, unsigned int height);
		virtual ~WindowCloseEvent();

		virtual EventType GetEventType() const override;
		virtual std::string ToString() const override;
	private:
		unsigned int m_width;
		unsigned int m_height;
	};
}

