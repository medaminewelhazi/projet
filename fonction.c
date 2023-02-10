#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"

// ****** traitement des images******/////
void initialiser_imageBACK(image *imge,int x,int y,int w,int h,char emplacement[])
{
    //  changement de l image
    imge->url = emplacement;
    imge->img = IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("unable to load background image %s \n", SDL_GetError());
        return;
    }

    imge->pos_img_ecran.x = x;
    imge->pos_img_ecran.y = y;

    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_affiche.h = h;
    imge->pos_img_affiche.w = w;
}

void initialiser_imageBOUTON(image *imge,int x,int y,int w,int h,char emplacement[])
{
    // chargement de l image
    imge->url = emplacement;
    imge->img = IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("unable to load background image %s \n", SDL_GetError());
        return;
    }
     imge->pos_img_ecran.x = x;
     imge->pos_img_ecran.y = y;

    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_affiche.h = h;
    imge->pos_img_affiche.w = w;
}

void afficher_image(SDL_Surface *screen, image imge)
{
    // Coller et afficher l image de back dans screen
    SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
}

void afficher_imageBTN(SDL_Surface *screen, image imge)
{
    // Coller et Afficher 1'image du btn play dans screen
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}

void liberer_image(image imge)
{
    SDL_FreeSurface(imge.img);
}
/********************************
****** *TRAITEMENT MUSIQUE* ******/

void initialiser_audio(Mix_Music *music,char emplacement[])
{
    // initialiser les fonction audio de SDL mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) == -1)
    {
        printf("%s", SDL_GetError());
    }
    music = Mix_LoadMUS(emplacement); // chargement de la musique
    Mix_PlayMusic(music, -1);              // jouer la musique
    Mix_VolumeMusic(100);
}

void liberer_musique(Mix_Music *music)
{
    Mix_FreeMusic(music);
}

void initialiser_audiobref(Mix_Chunk *music,char emplacement[])
{
       if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) == -1)
    {
        printf("%s", SDL_GetError());
    }
    music = Mix_LoadWAV(emplacement);
 Mix_PlayChannel(-1, music, 0);
    if (music == NULL)
        printf("%s\n", SDL_GetError());
}

void liberer_musiquebref(Mix_Chunk *music)
{
    Mix_FreeChunk(music);
}

//***************Traitement de texte ********

/*void initialiser_texte(texte *txte)
{
    TTF_Init();                                         // initialiser SDL_ttf
    txte->police = TTF_OpenFont("Ubuntu-Bold.ttf", 45); // chargement d une police et intialiser la taille
    txte->color_txt.r = 255;
    txte->color_txt.g = 255;
    txte->color_txt.b = 0;

    txte->pos_txt.x = 210;
    txte->pos_txt.y = 0;
}

void afficher_texte(SDL_Surface *screen, texte txte)
{
    txte.txt = TTF_RenderText_Blended(txte.police, " ", txte.color_txt); // ecrire le message "Bienvenu"
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);                      // coller la surface
}

void liberer_texte(texte txte)
{
    TTF_CloseFont(txte.police); // fermer la police
    TTF_Quit();                 // arreter la SDL_ttf
}*/
