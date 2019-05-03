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

	bool EventDispatcher::Dispatch()
	{
		if (/*if event type is ok return*/true)
		{
			m_event.m_isHandled = /*return call result*/true;
		}
		return {};
	}

}
