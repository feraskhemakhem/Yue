#include <Yue.h>

class Sandbox : public Yue::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Yue::Application* Yue::CreateApplication()
{
	return new Sandbox();
}