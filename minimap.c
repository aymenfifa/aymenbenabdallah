#include "minimap.h"
#include <SDL/SDL.h>

void init_map (minimap *m)
{ m -> map = IMG_Load("minimap.jpg");
  m-> minijoueur = IMG_Load("joueurmini.png");
  m->positionmap.x =250;
  m->positionmap.y =19;
  m->positionminijoueur.x =250;
  m->positionminijoueur.y =21;


  m->count=0;
  m->engPos.x=m->positionmap.x+m->map->w/2+30;
  m->engPos.y=m->positionmap.y+m->map->h/2+15;
  m->engPos.w=10;
  m->engPos.h=10;
}
void movemini (minimap *m, int sens)
{ if (sens == 0)
 m-> positionminijoueur.x+=4;
if (sens  == 1) 
 m-> positionminijoueur.x-=4;
}

void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement)
{
  SDL_Rect posJoueurABS;
  posJoueurABS.x = 0;
  posJoueurABS.y = 0;
  posJoueurABS.x = posJoueur.x + camera.x;
  posJoueurABS.y = posJoueur.y + camera.y;
  m->positionminijoueur.x=(posJoueurABS.x * redimensionnement/100)+250;
  m->positionminijoueur.y=(posJoueurABS.y * redimensionnement/100)+21;
}

void afficherminimap (minimap m, SDL_Surface * screen)
{
  SDL_BlitSurface(m.map,NULL,screen,&m.positionmap);
  SDL_BlitSurface(m.minijoueur,NULL,screen,&m.positionminijoueur);
}



SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y)
{
    SDL_Color color;
    Uint32 col = 0;
    // Determine Pos
    char *pPosition = (char *)pSurface->pixels;
    pPosition += (pSurface->pitch * y);
    pPosition += (pSurface->format->BytesPerPixel * x);
    memcpy(&col, pPosition, pSurface->format->BytesPerPixel);
    // convertir color
    SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);
    return (color);
}      


int collisionPP_black(SDL_Rect p, SDL_Surface *Masque,int direction){
    SDL_Color color;
    // 1 top
    // 2 rigth
    // 3 buttom
    // 4 left

    // right
    if(direction==2){
    for(int i=p.y;i<p.h+p.y;i++){
        color=GetPixel(Masque,p.x+p.w,i);
        if(color.r==0&&color.g==0&&color.b==0){
            return 1;
        }
    }
    }
    if(direction==4){
    // left
    for(int i=p.y;i<p.h+p.y;i++){
        color=GetPixel(Masque,p.x,i);
        if(color.r==0&&color.g==0&&color.b==0){
            return 1;
        }
    }
    }
    if(direction==1){
    // up
    for(int i=p.x;i<p.w+p.x;i++){
        color=GetPixel(Masque,i,p.y);
        if(color.r==0&&color.g==0&&color.b==0){
            return 1;
        }
    }
    }
    if(direction==3){
    // down
    for(int i=p.x;i<p.w+p.x;i++){
        color=GetPixel(Masque,i,p.y+p.h);
        if(color.r==0&&color.g==0&&color.b==0){
            return 1;
        }
    }
    }
    return 0;
}

int collisionPP_white(SDL_Rect p, SDL_Surface *Masque,int direction){
    SDL_Color color;
    // 1 top
    // 2 rigth
    // 3 buttom
    // 4 left

    // right
    if(direction==2){
    for(int i=p.y;i<p.h+p.y;i++){
        color=GetPixel(Masque,p.x+p.w,i);
        if(color.r==255&&color.g==255&&color.b==255){
            return 1;
        }
    }
    }
    if(direction==4){
    // left
    for(int i=p.y;i<p.h+p.y;i++){
        color=GetPixel(Masque,p.x,i);
        if(color.r==255&&color.g==255&&color.b==255){
            return 1;
        }
    }
    }
    if(direction==1){
    // up
    for(int i=p.x;i<p.w+p.x;i++){
        color=GetPixel(Masque,i,p.y);
        if(color.r==255&&color.g==255&&color.b==255){
            return 1;
        }
    }
    }
    if(direction==3){
    // down
    for(int i=p.x;i<p.w+p.x;i++){
        color=GetPixel(Masque,i,p.y+p.h);
        if(color.r==255&&color.g==255&&color.b==255){
            return 1;
        }
    }
    }
    return 0;
}


void animerMinimap(minimap *m,SDL_Surface* screen){
    m->count++;
    if(m->count>0&&m->count<100){
        m->engCol=SDL_MapRGB(screen->format,255,0,0);
    }    
    else if(m->count>=100&&m->count<200){
        m->engCol=SDL_MapRGB(screen->format,0,0,255);
    }
    if(m->count>=200)
        m->count=0;

    SDL_FillRect(screen,&m->engPos,m->engCol);
}