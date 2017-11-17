#include "fmap.h"
#include "SDL.h"
#include "fevent.h"
#include <stdlib.h>
#include <time.h>
#define SPRITE_SIZE 20
#define SIZE_IMAGE 160
#define LARGEUR_FENETRE 360
#define HAUTEUR_FENETRE 207
#define NBSPRITES 7

int gameover;

/* source and destination rectangles */
SDL_Rect rect, anim_pos;
SDL_Rect rect1,rect2,rect3,anim_pos1, anim_pos2, anim_pos3;
void HandleEvent(SDL_Event event);


void HandleEvent(SDL_Event event) 
{
	switch (event.type) {
		/* close button clicked */
		case SDL_QUIT:
			gameover = 1;
			break;
			
		/* handle the keyboard */
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
				case SDLK_q:
					gameover = 1;
					break;
				case SDLK_LEFT:		     
				        anim_pos.x = 0;
					rect.x -= 5;
					break;
				case SDLK_RIGHT:
				        anim_pos.x = 140;
				        rect.x += 5;
					break;
				case SDLK_UP:
				        anim_pos.x = 60;
				        rect.y -= 5;
					break;
				case SDLK_DOWN:
				        anim_pos.x = 100;
				        rect.y += 5;
					break;
			}
			break;
	}
}


int main(int argc,char* argv)
{  int colorkey;
  /* Sprite* sp[NBSPRITES];*/
  SDL_Surface *screen, *cars,*perso1, *perso2, *perso3, *tmp, *tmp1, *tmp2, *tmp3;
  Map* m;
  SDL_Init(SDL_INIT_VIDEO);// prepare SDL
  SDL_WM_SetCaption("KILLER MAN", "KILLER MAN");
  screen = SDL_SetVideoMode(360, 208, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  m = ChargerMap("level.txt");
  AfficherMap(m,screen);
  
  /* set keyboard repeat */
  SDL_EnableKeyRepeat(70, 70);

  /* load sprite cars*/
  tmp = SDL_LoadBMP("charset.bmp");
  cars = SDL_DisplayFormat(tmp);
  SDL_FreeSurface(tmp);

  /*load sprite perso*/
  /*PERSO1*/
  tmp1 = SDL_LoadBMP("charset1.bmp");
  perso1 = SDL_DisplayFormat(tmp1);
  SDL_FreeSurface(tmp1);
   /*PERSO2*/
  tmp2 = SDL_LoadBMP("charset2.bmp");
  perso2 = SDL_DisplayFormat(tmp2);
  SDL_FreeSurface(tmp2);
  /*PERSO3*/
  tmp3 = SDL_LoadBMP("charset3.bmp");
  perso3 = SDL_DisplayFormat(tmp3);
  SDL_FreeSurface(tmp3);

	
  /* setup sprite colorkey CARS */
  //colorkey = SDL_MapRGB(perso->format, 255, 0, 255); rose
  colorkey = SDL_MapRGB(cars->format, 255, 0, 0);
  SDL_SetColorKey(cars, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  /* setup sprite colorkey PERSO1 */
  colorkey = SDL_MapRGB(perso1->format, 255, 0, 255); 
  SDL_SetColorKey(perso1, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  /* setup sprite colorkey PERSO2 */
  colorkey = SDL_MapRGB(perso2->format, 255, 0, 255); 
  SDL_SetColorKey(perso2, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  /* setup sprite colorkey PERSO3 */
  colorkey = SDL_MapRGB(perso3->format, 255, 0, 255);
  SDL_SetColorKey(perso3, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);


	
  /* set sprite position CARS */
  rect.x = 0;
  rect.y = 0;

 /* set sprite position PERSO1 */
  rect1.x = 20;
  rect1.y = 20;
 /* set sprite position PERSO2 */
  rect2.x = 60;
  rect2.y = 60;
 /* set sprite position PERSO3  */
  rect3.x = 100;
  rect3.y = 100;
 
  /* set animation frame  CARS*/
  anim_pos.x = 0;
  anim_pos.y = 0;
  anim_pos.w = 20;
  anim_pos.h = 20;
  
  /* set animation frame PERSO1 */
  anim_pos1.x = 100;
  anim_pos1.y = 0;
  anim_pos1.w = 20;
  anim_pos1.h = 20;
  /* set animation frame PERSO2 */
  anim_pos2.x = 120;
  anim_pos2.y = 0;
  anim_pos2.w = 20;
  anim_pos2.h = 20;
  /* set animation frame PERSO3 */
  anim_pos3.x = 140;
  anim_pos3.y = 0;
  anim_pos3.w = 20;
  anim_pos3.h = 20;
	
  //Sprite* perso;
  //perso = InitialiserSprite(101,150,50,100);
  //Animation* An = ChargerAnimation("animat.txt");
  //InitSprites(sp,An);
  //SDL_Flip(screen);
  gameover=0;
	
  while (!gameover)
    {
      SDL_Event event;
		
      /* look for an event */
      if (SDL_PollEvent(&event)) {
	HandleEvent(event);
      }

      /* collide with edges of screen */
      if (rect.x <= 0)//fenetre gauche
	rect.x = 0;
      if (rect.x >= LARGEUR_FENETRE - SPRITE_SIZE) //fenetre droiter
	rect.x = LARGEUR_FENETRE - SPRITE_SIZE;//fenetre droite

      if (rect.y <= 0)//fenetre bas
	rect.y = 0;
      if (rect.y >= HAUTEUR_FENETRE - SPRITE_SIZE) //fenetre haut
	rect.y = HAUTEUR_FENETRE - SPRITE_SIZE;

      /*PERSO ANIMATION*/
      for(anim_pos1.x=0;anim_pos1.x<=10;anim_pos1.x=anim_pos1.x+20){
      	SDL_BlitSurface(perso1,&anim_pos1,screen,&rect1);
      }
	  
      /* draw the sprite */
      AfficherMap(m,screen);
      SDL_BlitSurface(cars,&anim_pos,screen,&rect);
      //SDL_BlitSurface(perso1,&anim_pos1,screen,&rect1);
      SDL_BlitSurface(perso1,&anim_pos1,screen,&rect1);
      SDL_BlitSurface(perso2,&anim_pos2,screen,&rect2);
      SDL_BlitSurface(perso3,&anim_pos3,screen,&rect3);
      SDL_Flip(cars);
      SDL_Flip(perso1);
      SDL_Flip(perso2);
      SDL_Flip(perso3);

      /* update the screen */
      SDL_UpdateRect(screen, 0, 0, 0, 0);

    }
	
  //SDL_FreeSurface(perso);
  LibererMap(m);
  SDL_Quit();

  return 0;
}



