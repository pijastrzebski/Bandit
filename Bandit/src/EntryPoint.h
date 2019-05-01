#pragma once

#include "Application.h"
#include <memory>
#include <cstdlib>

#ifdef BANDIT_PLATFORM_WIN

extern std::unique_ptr<Bandit::Application> Bandit::CreateApplication();

int main(int argc, char** argv)
{
	std::puts("Bandit Engine\n");

	auto app = Bandit::CreateApplication();
	app->Run();
}

#endif
