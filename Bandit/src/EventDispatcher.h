#pragma once

#include "IEvent.h"

namespace Bandit {

	class BANDIT_API EventDispatcher
	{
	public:
		EventDispatcher(IEvent& event);
		virtual ~EventDispatcher();

		bool Dispatch();

	private:
		IEvent& m_event;
	};
}
