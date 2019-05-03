#pragma once

#include "Application.h"

#ifdef BANDIT_PLATFORM_WIN

extern std::unique_ptr<Bandit::Application> Bandit::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Bandit::CreateApplication();	
	app->Run();
}

#endif
