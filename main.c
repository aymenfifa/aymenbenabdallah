


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "minimap.h"
#include "temps.h"



int main()
{
    TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen , *mask, *perso;
screen=SDL_SetVideoMode (800,537,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Rect camera,posperso;
SDL_Event event;
minimap m;
temps t;
SDL_Surface *back;
perso=IMG_Load("hero.png");
back=IMG_Load("map.jpg");
mask=IMG_Load("mask.png"); 
int continuer=1;
init_map(&m);
camera.x=0;
camera.y=0;
camera.w=1300;
camera.h=700;
posperso.x=0; 
posperso.y=260;
SDL_EnableKeyRepeat(100,10);////
initialiser_temps(&t);

int showEng=0;
while(continuer)
{
    
    SDL_BlitSurface(back,NULL,screen,NULL);
    SDL_BlitSurface(perso,NULL,screen,&posperso);


MAJMinimap(posperso ,  &m, camera, 20);
afficherminimap(m,screen);

afficher_temps(&t,screen);


while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:

			continuer=0;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
           case SDLK_LEFT:
                 
                if (collisionPP_white(posperso,mask,4)==1)
                 {
                       showEng=1;
                 }
                 else if (collisionPP_black(posperso,mask,4)==0)
                 {
                       posperso.x-=5; 
                 }
                  if(collisionPP_white(posperso,mask,4)==0){
                    showEng=0;
                 }
                break;
                case SDLK_RIGHT:
                   
                   
                   
                    if (collisionPP_white(posperso,mask,2)==1)
                 {
                       showEng=1;
                 }
                 else if (collisionPP_black(posperso,mask,2)==0)
                   posperso.x+=5;
                    if(collisionPP_white(posperso,mask,2)==0){
                    showEng=0;
                 }
                break;
                case SDLK_UP:
                    
                    if (collisionPP_white(posperso,mask,1)==1)
                 {
                       showEng=1;
                 }
                 else if (collisionPP_black(posperso,mask,1)==0) posperso.y-=5;
                  if(collisionPP_white(posperso,mask,1)==0){
                    showEng=0;
                 }
                break;  
                case SDLK_DOWN:
                    
                    if (collisionPP_white(posperso,mask,3)==1)
                 {
                    showEng=1;
                       
                 }
                 else if (collisionPP_black(posperso,mask,3)==0) 
                    {
                        posperso.y+=5;
                        if(posperso.y+perso->h>=537)
                            posperso.y=537-perso->h;
                    }
                     if(collisionPP_white(posperso,mask,3)==0){
                    showEng=0;
                 }
                break;  

            }
            break;
            
        }
    }        







if(showEng==1){
animerMinimap(&m,screen);
}



SDL_Flip(screen);
//SDL_Delay();

}

    return 0;
}





