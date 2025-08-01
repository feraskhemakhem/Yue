#pragma once

#ifdef YUE_PLATFORM_WINDOWS

extern Yue::Application* Yue::CreateApplication();

int main(int argc, char** argv)
{

	Yue::Log::Init();
	int a = 5;
	YUE_CORE_INFO("CORE INFO HERE");
	YUE_WARN("CLIENT WARNING: INFO {0}", __cplusplus);

	auto app = Yue::CreateApplication();
	app->Run();
	delete app;

}

#else
	#error Yue only supports Windows
#endif