#pragma once

#include "Core.h"
#include <memory>

namespace Bandit 
{
	class BANDIT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// in client
	std::unique_ptr<Application> CreateApplication();

}

