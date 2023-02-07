#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
 #include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"


int main()
{
    //Declaration des variables 
SDL_Surface *screen;
 image IMAGE, IMAGE_BTN1, IMAGE_BTN2;
Mix_Music *music;
Mix_Chunk *mus;
texte txte;
SDL_Event event;
 int boucle=1;


// initialisation de la SDL 

 if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
 {
 printf("Could not initialize SDL: %s.\n",SDL_GetError());
 return -1;
 }

 // reglage de la fenetre 
 screen=SDL_SetVideoMode(1280,720,0,SDL_SWSURFACE|SDL_DOUBLEBUF);
 // initialisation
initialiser_imageBACK(&IMAGE);
initialiser_imageBOUTON1 (&IMAGE_BTN1);
initialiser_imageBOUTON2(&IMAGE_BTN2);
initialiser_audio(music) ;
initialiser_texte(&txte) ;

/****************/
// boucle de menu 
/***************/
while(boucle)
{
afficher_imageBMP(screen, IMAGE); //afficher l image de background
afficher_imageBTN1(screen, IMAGE_BTN1); //afficher le bouton play
afficher_imageBTN2(screen, IMAGE_BTN2) ; // afficher le bouton play
afficher_texte(screen, txte);
while(SDL_PollEvent(&event))
{
switch(event.type)
{
case SDL_QUIT:
boucle=0;
break;
case SDL_MOUSEBUTTONDOWN: // quitter le menu 
if(event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=300 && event.motion. y>=250 && event.motion.x<=423 && event.motion.x>=213))
boucle=0; //quitter le menu 
break;
case SDL_MOUSEMOTION:
if(event.motion.y<=150 && event.motion.y>=100 && (event.motion.x<=423 && event.motion.x>=213))
initialiser_audiobref(mus); // jouer un son bref 
break;
}
}
SDL_Flip(screen); //reffraichir l ecran
SDL_Delay(5000); 
}
//liberer les surfaces 
liberer_image(IMAGE);
liberer_image(IMAGE_BTN1);
liberer_image(IMAGE_BTN2);
// liberer la musique
liberer_musique(music);
liberer_musiquebref(mus) ;
//liberer texte 
liberer_texte (txte);
//quitter SDL 
SDL_Quit();
return 0 ;
}














