#pragma warning( disable: 4244 4251 ) // suppress spdlog compiler warnings 

#pragma once

#include "IEvent.h"

namespace Bandit {

	class BANDIT_API EventDispatcher
	{	

	public:
		EventDispatcher(IEvent& event);
		virtual ~EventDispatcher();

		bool Dispatch(std::function<bool()> handleEventCallback);

	private:
		IEvent& m_event;
	};
}
