#pragma warning( disable: 4244 4251 ) // suppress spdlog compiler warnings 

#pragma once

#include "Core.h"
#include <memory>

#include "spdlog/spdlog.h"

namespace Bandit {

	class BANDIT_API Logger
	{
		friend class Application;

	public:
		Logger();
		virtual ~Logger();
		
		void Init();

	private:
		std::shared_ptr<spdlog::logger> m_coreLogger;
		std::shared_ptr<spdlog::logger> m_appLogger;
	};

}

