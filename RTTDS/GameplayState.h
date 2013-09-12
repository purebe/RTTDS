#ifndef GAMEPLAYSTATE_H_
#define GAMEPLAYSTATE_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "CState.h"

class GameplayState : public CState
{
private:
	TTF_Font * font;
	Mix_Music * music;

public:
	GameplayState();

	void Load(void);
	void Render(void);
	void Update(void);
	void Unload(void);
};

#endif