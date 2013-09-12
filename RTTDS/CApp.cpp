#include "CApp.h"

CApp::CApp()
{
	gameIsRunning = true;
}

void CApp::Startup(void)
{
	// Initialize and setup SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}

	window = SDL_CreateWindow("RTTDS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		1280, 720, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cerr << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}

	renderer = SDL_CreateRenderer(window, -1,
								SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		std::cerr << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}

	// Initialize extension libraries
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		std::cerr << "IMG_Init error: " << IMG_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}

	if (TTF_Init() == -1)
	{
		std::cerr << "TTF_Init error: " << TTF_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}

	if (Mix_Init(MIX_INIT_OGG) != MIX_INIT_OGG)
	{
		std::cerr << "Mix_Init error: " << Mix_GetError() << std::endl;
		//	exit(EXIT_FAILURE); - non critical error
	}
}

void CApp::Run(void)
{
	// Game loop thanks to: http://www.koonsolo.com/news/dewitters-gameloop/
	const int FRAMES_PER_SECOND = 60;
	const int SKIP_TICKS = 1000 / FRAMES_PER_SECOND;

	Uint32 nextGameTick = SDL_GetTicks();

	int sleepTime = 0;

	state = new GameplayState();
	state->SetRenderer(renderer);
	state->Load();

	while (gameIsRunning)
	{
		if (state->nextState != States::CURRENT)
		{
			switch (state->nextState)
			{
			case States::EXIT:
				gameIsRunning = false;
				break;

			case States::MENU:
				break;

			case States::GAMEPLAY:
				state->Unload();
				delete state;

				state = new GameplayState();
				state->SetRenderer(renderer);
				state->Load();
				break;
			}
		}

		state->Update();
		state->Render();

		nextGameTick += SKIP_TICKS;
		sleepTime = nextGameTick - SDL_GetTicks();
		if (sleepTime >= 0)
		{
			SDL_Delay(sleepTime);
		}
	}
}

void CApp::Shutdown(void)
{
	state->Unload();

	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}