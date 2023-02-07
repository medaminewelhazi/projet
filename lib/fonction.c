#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"


// ****** traitement des images******/////
void initialiser_imageBACK (image *imge)
{
//  changement de l image 
imge->url="bg.bmp";
imge->img=SDL_LoadBMP(imge->url);
 if (imge->img==NULL) 
 {
     printf ("unable to load background image %s \n", SDL_GetError ());
     return ;
     }
imge->pos_img_ecran.x=0;
imge->pos_img_ecran.y=0;
imge->pos_img_affiche.x=0;
imge->pos_img_affiche.y=0;
imge->pos_img_affiche.h=720;
imge->pos_img_affiche.w=1280;
}

void initialiser_imageBOUTON1(image *imgbtn)
{
//chargement de l image 
imgbtn->url="play.png";
imgbtn->img=IMG_Load(imgbtn->url);
if(imgbtn->img == NULL) {
printf ("unable to load background image %s \n", SDL_GetError());
return ; }
imgbtn->pos_img_affiche.x=0;
imgbtn->pos_img_affiche.y=0;
imgbtn->pos_img_affiche.w=237;
imgbtn->pos_img_affiche.h=58;
imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2);
imgbtn->pos_img_ecran.y=((SCREEN_H-imgbtn->pos_img_affiche.h)/3);
}

void initialiser_imageBOUTON2 (image *imgbtn)
{
//chargement de l'image
imgbtn->url="exit.png";
imgbtn->img=IMG_Load(imgbtn->url);
if (imgbtn->img == NULL) {
printf("unable to load background image %s \n", SDL_GetError ()) ;
 return ;}
imgbtn->pos_img_affiche.x=0;
imgbtn->pos_img_affiche.y=0;
imgbtn->pos_img_affiche.w=236;
imgbtn->pos_img_affiche.h=58;
imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2);
imgbtn->pos_img_ecran.y=(2*(SCREEN_H-imgbtn->pos_img_affiche.h)/3) ;
}
void afficher_imageBMP(SDL_Surface *screen, image imge)
{
    // Coller et afficher l image de back dans screen
    SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
    
}


void afficher_imageBTN1(SDL_Surface *screen, image imge)
{
//Coller et Afficher 1'image du btn play dans screen
SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}


void afficher_imageBTN2(SDL_Surface *screen, image imge)
{
//Coller et Afficher 1'image du btn quit dans screen
SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}


void liberer_image(image imge)
{
SDL_FreeSurface (imge.img);
}
/********************************
****** *TRAITEMENT MUSIQUE* ******/

void initialiser_audio(Mix_Music *music)
{
//initialiser les fonction audio de SDL mixer
if(Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) ==-1) {
printf("%s",SDL_GetError () );
}
music=Mix_LoadMUS("Cool Ringtone.mp3") ;//chargement de la musique
Mix_PlayMusic (music,-1) ;//jouer la musique
Mix_VolumeMusic (MIX_MAX_VOLUME/3.5);
}

void liberer_musique (Mix_Music *music)
{
Mix_FreeMusic(music);
}

void initialiser_audiobref (Mix_Chunk *music)
{
Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, 2, 2048) ;
music = Mix_LoadWAV("Button click sound sound effect.mp3");
Mix_PlayChannel(-1, music, 0 );
if(music==NULL) printf("%s", SDL_GetError ());
}


void liberer_musiquebref (Mix_Chunk *music)
{
Mix_FreeChunk(music);
}

//***************Traitement de texte ********


void initialiser_texte (texte *txte)
{
TTF_Init(); // initialiser SDL_ttf
txte->police = TTF_OpenFont ("Ubuntu-Bold.ttf", 45);  //chargement d une police et intialiser la taille
txte->color_txt.r=255;
txte->color_txt.g=255;
txte->color_txt.b=0;

txte->pos_txt.x=210;
txte->pos_txt.y=0;
}

void afficher_texte (SDL_Surface *screen, texte txte)
{
txte.txt=TTF_RenderText_Blended(txte.police,"Bienvenue",txte.color_txt); //ecrire le message "Bienvenu"
SDL_BlitSurface(txte.txt, NULL, screen,&txte.pos_txt); // coller la surface
}

void liberer_texte (texte txte)
{
TTF_CloseFont (txte.police);  //fermer la police
TTF_Quit(); // arreter la SDL_ttf
}
