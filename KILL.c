/**********************************************************/
/**     MANANJARA Lynda Garcia                      *******/
/***              &                                 *******/
/***    MANANJARA Linah Chilande                    *******/
/***      PROJET PROGRAMMATION AVANCEE  2017-2018   *** ***/
/**********************************************************/            
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


/*void HandleEvent(SDL_Event event)
{*/
  // switch (event.type) {
    /* close button clicked */
    /*case SDL_QUIT:
    gameover = 1;
    break;*/
   
    /* handle the keyboard */
    /*case SDL_KEYDOWN:
    switch (event.key.keysym.sym) {
    case SDLK_ESCAPE:
    case SDLK_SPACE:
      theta=PI-((pos_arrow+2)*(PI/LAUNCHER_DIV));
      dir_x=cos(theta)*VELOCITY;
      dir_y=-sin(theta)*VELOCITY;
     
      moov=true;
      break;
    case SDLK_q:
      gameover = 1;
      break;
    case SDLK_LEFT:
      if(rcSrc.y>314) {
	rcSrc.y=rcSrc.y-157;
	pos_arrow-=1;
      }
      else
	rcSrc.y=314;
      break;
    case SDLK_RIGHT:
      if(rcSrc.y<=6437) {
	rcSrc.y=rcSrc.y+157;
	pos_arrow+=1;
      }
      else
	rcSrc.y<=6437;
      break;	 
    }
    break;
  }
}*/

/******* main****************/
int main(int argc, char* argv[])
{
  SDL_Surface *screen, *image_fond;
  SDL_Rect rcfond;
  
  rcfond.x = 0;
  rcfond.y = 0;

  SDL_Init(SDL_INIT_VIDEO);
  
  screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
  
  /* Chargement d'une image Bitmap dans une surface */
  image_fond = SDL_LoadBMP("fondkiller.bmp");

  /* On blitte par-dessus l'écran */

  SDL_BlitSurface(image_fond, NULL, screen, &rcfond);
  SDL_Flip(screen);
  //pause();
  SDL_FreeSurface(image_fond); /* On libère la surface */

  SDL_Quit();
  return  EXIT_SUCCESS;
}
