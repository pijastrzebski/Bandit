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

	bool EventDispatcher::Dispatch(std::function<bool()> functor)
	{
		//TODO: simplify the dispatcher
		m_event.m_isHandled = functor();
		return m_event.m_isHandled;		
	}

}
