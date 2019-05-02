#include "Application.h"

namespace Bandit {

	Application::Application() :
		m_logger(std::make_unique<Bandit::Logger>())
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true)
		{

		}
	}
}

