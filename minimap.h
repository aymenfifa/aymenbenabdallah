#ifndef minimap_H
#define minimao_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{SDL_Surface *map;
SDL_Surface  *minijoueur;
SDL_Rect positionmap,engPos;
SDL_Rect positionminijoueur;
Uint32 engCol;
int count;

}minimap;
void init_map (minimap *m);
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement);
void afficherminimap (minimap m, SDL_Surface * screen);
void movemini (minimap *m, int sens);

SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y);
int collisionPP_black(SDL_Rect p, SDL_Surface *Masque,int direction);
int collisionPP_white(SDL_Rect p, SDL_Surface *Masque,int direction);
#endif

