#include <Bandit.h>
#include <memory>

class Sandbox : public Bandit::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

std::unique_ptr<Bandit::Application> Bandit::CreateApplication()
{
	return std::make_unique<Sandbox>();
}