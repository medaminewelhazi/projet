#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"

int main()
{
    // Declaration des variables
    SDL_Surface *screen;
    image IMAGE, IMAGE_BTN1, IMAGE_BTN2, IMAGE_BTN3;
    image IMAGE_BTN4, IMAGE_BTN5, IMAGE_BTN6;
    Mix_Music *music;
    Mix_Chunk *mus;
    // texte txte;
    SDL_Event event;
    int boucle = 1, tt = 0, tt1 = 0, tt2 = 0;
    int detect = 0;

    // initialisation de la SDL

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == -1)
    {
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        return -1;
    }
    // reglage de la fenetre
    screen = SDL_SetVideoMode(1920, 1080, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    // initialisation
    //(image *imge,int x,int y,int w,int h,char emplacement[]);
    initialiser_imageBACK(&IMAGE,0,0,1920,1080,"bg.jpg");
    initialiser_imageBOUTON(&IMAGE_BTN1,800,300,320,130,"PLAY1.png");
    initialiser_imageBOUTON(&IMAGE_BTN2,800,500,320,130,"SETTING1.png");
    initialiser_imageBOUTON(&IMAGE_BTN3,800,700,320,130,"QUIT1.png");

    initialiser_imageBOUTON(&IMAGE_BTN4,800,300,320,130,"PLAY2.png");
    initialiser_imageBOUTON(&IMAGE_BTN5,800,500,320,130,"SETTING2.png");
    initialiser_imageBOUTON(&IMAGE_BTN6,800,700,320,130,"QUIT2.png");

    initialiser_audio(music,"backgmusic.wav");
    //initialiser_audiobref(mus,"beep.wav");
    // initialiser_texte(&txte);

    /****************/
    // boucle de menu
    /***************/
       
    while (boucle)
    {
        afficher_image(screen, IMAGE);       // afficher l image de background
        afficher_image(screen, IMAGE_BTN1); // afficher le bouton play
        afficher_image(screen, IMAGE_BTN2); // afficher le bouton setting
        afficher_image(screen, IMAGE_BTN3); // afficher le bouton  quit
        if(detect==1)
        afficher_image(screen, IMAGE_BTN4);
                if(detect==2)
        afficher_image(screen, IMAGE_BTN5);
                if(detect==3)
        afficher_image(screen, IMAGE_BTN6);
        // afficher_texte(screen, txte);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                boucle = 0;
                break;
            case SDL_MOUSEBUTTONDOWN: // quitter le menu
                if (detect == 1)
                   initialiser_audiobref(mus,"mus.wav");
                    if (detect == 3)
                   boucle=0;
                break;
            case SDL_MOUSEMOTION:
                if((event.motion.x>IMAGE_BTN1.pos_img_ecran.x)&&(event.motion.x<IMAGE_BTN1.pos_img_ecran.x+340)&&(event.motion.y>IMAGE_BTN1.pos_img_ecran.y)&&(event.motion.y<IMAGE_BTN1.pos_img_ecran.y+130))
                {detect = 1;
                printf("1\n");
                
                }

                else if((event.motion.x>IMAGE_BTN2.pos_img_ecran.x)&&(event.motion.x<IMAGE_BTN2.pos_img_ecran.x+340)&&(event.motion.y>IMAGE_BTN2.pos_img_ecran.y)&&(event.motion.y<IMAGE_BTN2.pos_img_ecran.y+130))
                {detect = 2;
                printf("2\n");
                
                }
                else if((event.motion.x>IMAGE_BTN3.pos_img_ecran.x)&&(event.motion.x<IMAGE_BTN3.pos_img_ecran.x+340)&&(event.motion.y>IMAGE_BTN3.pos_img_ecran.y)&&(event.motion.y<IMAGE_BTN3.pos_img_ecran.y+130))
                {detect = 3;
                printf("3\n");
                
                }
                else 
                detect = 0;
                break;
            }
        }
        SDL_Flip(screen); // reffraichir l ecran
        // SDL_Delay(5000);
    }
    // liberer les surfaces
    liberer_image(IMAGE);
    liberer_image(IMAGE_BTN1);
    liberer_image(IMAGE_BTN2);
    liberer_image(IMAGE_BTN3);
    // liberer la musique
    liberer_musique(music);
    liberer_musiquebref(mus);
    // liberer texte
    // liberer_texte(txte);
    // quitter SDL
    SDL_Quit();
    return 0;
}
