#pragma once

#include "bpch.h"
#include "Core.h"
#include "spdlog/fmt/ostr.h"

namespace Bandit {

	struct BANDIT_API IEvent
	{
		enum EventType
		{
			//TODO: add more events
			None = 0,
			WindowClose,
			KeyPressed, KeyReleased
		};
	
		enum EventCategory
		{
			//TODO: impl
		};
		
		friend std::ostream& operator<<(std::ostream& os, const IEvent& c)
		{
			return os << "[my_type i=" << c.GetEventType() << "]";
		}

		virtual EventType GetEventType() const = 0;
		virtual std::string ToString() const = 0;

		bool m_isHandled{};
	};
}
