#ifndef FMAP_H
#define FMAP_H
#include "SDL.h"
#include <stdlib.h>


typedef struct
{
  SDL_Rect R;
  int mur; //plein ou vide
} TileProp;

typedef struct
{
  int LARGEUR_TILE,HAUTEUR_TILE;//une image du tableau
  int nbtilesX,nbtilesY;//nombre de tile dans tileset en x et en y ici (8 1)
  SDL_Surface* tileset;//liens vers la tileset chargé
  TileProp* props;//un struct SDL_RECT ET MUR et PROP un tab[nbtileX*nbtileY]
  Uint16** schema;//tab[nbtiles_largeur_mondeX*nbtiles_hauteur_mondeY]
  int nbtiles_largeur_monde,nbtiles_hauteur_monde;//element du tableau
} Map;

void ChargerMap_tileset(FILE* F,Map* m);
void ChargerMap_level(FILE* F,Map* m);
Map* ChargerMap(const char* fic);
int AfficherMap(Map* m,SDL_Surface* screen);
int LibererMap(Map* m);

#endif
