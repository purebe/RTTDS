#ifndef CAPP_H_
#define CAPP_H_

#pragma comment(lib, "SDL2main")
#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2_image")
#pragma comment(lib, "SDL2_ttf")
#pragma comment(lib, "SDL2_mixer")

#include <SDL.h>
#include <iostream>

#include "CState.h"
#include "GameplayState.h"

class CApp
{
private:
	SDL_Window * window;
	SDL_Renderer * renderer;

	bool gameIsRunning;

	CState * state;

public:
	CApp(void);

	void Startup(void);
	void Run(void);
	void Shutdown(void);
};

#endif