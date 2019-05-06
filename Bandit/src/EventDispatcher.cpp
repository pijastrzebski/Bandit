#include "bpch.h"
#include "EventDispatcher.h"

namespace Bandit {

	EventDispatcher::EventDispatcher(IEvent& event) :
		m_event(event)
	{
	}


	EventDispatcher::~EventDispatcher()
	{
	}

	bool EventDispatcher::Dispatch(std::function<bool()> handleEventCallback)
	{
		m_event.m_isHandled = handleEventCallback();		
		return m_event.m_isHandled;		
	}

}
