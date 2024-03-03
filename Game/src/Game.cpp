#include <Henio.h>

#include "Henio/Logger.h"

class Game : public Henio::Application
{
public:
	Game()
	{
		LOG_MESSAGE("Game created")
	}

	~Game()
	{
		LOG_MESSAGE("Game destroyed")
	}

	virtual void Run() override
	{
		while (true)
		{
			LOG_MESSAGE("Game running")
		}
	}
};

Henio::Application* Henio::CreateApplication()
{
	return new Game();
}