#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 410
#define SCREEN_W 640


typedef struct
{
char *url;
SDL_Rect pos_img_affiche; // partie de l'image qui doit etre affiché
SDL_Rect pos_img_ecran;   // position de l image par rapport l ecran 
SDL_Surface *img;
}image;


typedef struct
{
SDL_Surface *txt;
SDL_Rect pos_txt;
SDL_Colour color_txt;
TTF_Font *police;
}texte;


//image
 void initialiser_imageBACK (image *imge);
 void initialiser_imageBOUTON1 (image *imgbtn);
 void initialiser_imageBOUTON2 (image *imgbtn);
//image                               
void afficher_imageBMP (SDL_Surface  *screen, image imge);
void afficher_imageBTN1 (SDL_Surface *screen, image imge); 
void afficher_imageBTN2 (SDL_Surface *screen, image imge);       
void liberer_image (image imge);
//audio
void initialiser_audio (Mix_Music *music);
void liberer_musique (Mix_Music *music);
void initialiser_audiobref (Mix_Chunk *music);
void liberer_musiquebref (Mix_Chunk *music);
// texte
void initialiser_texte (texte *txte);
void afficher_texte (SDL_Surface *screen, texte txte);
void liberer_texte (texte txte);
#endif


 

