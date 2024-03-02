#include <Henio.h>

class Game : public Henio::Application
{
public:
	Game()
	{

	}

	~Game()
	{

	}
};

Henio::Application* Henio::CreateApplication()
{
	return new Game();
}