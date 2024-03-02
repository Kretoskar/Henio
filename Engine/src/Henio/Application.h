#pragma once

#include "Core.h"

namespace Henio
{
	class HENIO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined by client
	Application* CreateApplication();
}