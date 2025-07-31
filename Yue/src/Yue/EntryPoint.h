#pragma once

#ifdef YUE_PLATFORM_WINDOWS

extern Yue::Application* Yue::CreateApplication();

int main(int argc, char** argv)
{

	auto app = Yue::CreateApplication();
	app->Run();
	delete app;

}

#else
	#error Yue only supports Windows
#endif