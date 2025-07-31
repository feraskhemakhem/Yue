#pragma once
#include "Core.h"

namespace Yue {

	class YUE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// needs to be defined in client application
	// declared to avoid dangerous neglect
	Application* CreateApplication();

}

