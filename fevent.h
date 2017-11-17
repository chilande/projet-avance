#ifndef FEVENT_H
#define FEVENT_H
#include <SDL/SDL.h>

typedef struct
{
	char key[SDLK_LAST];
	int mousex,mousey;
	int mousexrel,mouseyrel;
	char mousebuttons[8];
	char quit;
} Input;

void UpdateEvents(Input* in);
void InitEvents(Input* in);

#endif
