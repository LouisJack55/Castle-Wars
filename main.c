#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
#define Taille_Carte_X  60 //Taille de la carte sur l'axe x en unité de case 20 pixels
#define Taille_Carte_Y  40 //Taille carte en unité de case 20 px sur l'axe y
#define Hauteur_px  1200 //Hauteur carte en pixels
#define Largeur_px  800 //Largeur carte en pixels




int main(int argc, char *argv[])

{
    SDL_Init(SDL_INIT_VIDEO);
    // SDL_Surface *perso[4]= {NULL}; //Pointeur vers tableau qui contient les 4 positions du joueur
    SDL_Surface *colline=NULL,*montagne=NULL,*objectif=NULL,*fort=NULL,*foret=NULL,*eau=NULL,*ecran,*mapp,*perso;
    SDL_Rect position, positionJoueur; //position pour le joueur et une variable pour une position utile
    SDL_Event event; //variable qui contient la gestion des evenements
    ecran=SDL_SetVideoMode(1200,800,32,SDL_HWSURFACE);

    int continuer=1,i=0,j=0;
    int colline2=10,montagne2=20,objectif2=30,fort2=40,foret2=50,eau2=60; //variables utiles pour gérer les collisions et les propriétés de la map

    position.x=0;
    position.y=0;



    mapp= SDL_LoadBMP("ProjetProg.bmp"); //charge l'image dans la variable mapp
    SDL_BlitSurface(mapp,NULL,ecran,&position); //blit la mapp sur ecran

    positionJoueur.x=1200/2;
    positionJoueur.y=800/2;

    perso=SDL_LoadBMP("perso.bmp");
    SDL_BlitSurface(perso, NULL, ecran, &positionJoueur);
    SDL_SetColorKey(perso, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format, 0, 64, 192));

    SDL_Flip(ecran);//raffraichit l'ecran
    SDL_Flip(mapp);

    SDL_EnableKeyRepeat(300, 300); //autorise la répérition de touches
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer=0;
                break;
            case SDLK_UP:
                positionJoueur.y=positionJoueur.y-20;
                break;
            case SDLK_DOWN:
                positionJoueur.y=positionJoueur.y+20;
                break;
            case SDLK_RIGHT:
                positionJoueur.x=positionJoueur.x+20;
                break;
            case SDLK_LEFT:
                positionJoueur.x=positionJoueur.x-20;
                break;

            }

        }

        SDL_BlitSurface(mapp,NULL,ecran,&position); // on efface l'ecran

        SDL_BlitSurface(perso, NULL, ecran, &positionJoueur); // on place le personnage a la nouvelle position

        SDL_Flip(ecran); // on met à jour l'ecran


    }


    SDL_Quit();
    return 0;
}
