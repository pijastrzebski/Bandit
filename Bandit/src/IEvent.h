#pragma once

#include "bpch.h"
#include "Core.h"

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

		virtual EventType GetEventType() const = 0;
		virtual std::string ToString() const = 0;

		bool m_isHandled{};
	};
}
