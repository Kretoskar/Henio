#pragma once

#ifdef HENIO_PLATFORM_WINDOWS

extern Henio::Application* Henio::CreateApplication();

void main(int argc, char** argv)
{
	auto app = Henio::CreateApplication();
	app->Run();
	delete app;
}

#endif