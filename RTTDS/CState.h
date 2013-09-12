#ifndef CSTATE_H_
#define CSTATE_H_

#include <SDL.h>

enum class States {CURRENT, MENU, GAMEPLAY, EXIT};

class CState
{
protected:
	SDL_Renderer * renderer;
public:
	virtual void Load(void) = 0;
	virtual void Render(void) = 0;
	virtual void Update(void) = 0;
	virtual void Unload(void) = 0;

	virtual void SetRenderer(SDL_Renderer * sdlRenderer)
	{ renderer = sdlRenderer; }

	States nextState;

	CState() : nextState(States::CURRENT) { }
};

#endif