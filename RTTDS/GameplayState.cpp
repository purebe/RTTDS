#include "GameplayState.h"

GameplayState::GameplayState()
{
}

void GameplayState::Load(void)
{
}

void GameplayState::Render(void)
{
}

void GameplayState::Update(void)
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT )
		{
			nextState = States::EXIT;
		}
	}
}

void GameplayState::Unload(void)
{
}