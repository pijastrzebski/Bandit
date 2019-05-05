#pragma once

#include "IEvent.h"

namespace Bandit {

	class BANDIT_API EventDispatcher
	{	

	public:
		EventDispatcher(IEvent& event);
		virtual ~EventDispatcher();

		bool Dispatch(std::function<bool()> functor);

	private:
		IEvent& m_event;
	};
}
