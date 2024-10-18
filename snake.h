#ifndef __SNAKE__
#define __SNAKE__

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unistd.h>
#include <time.h>

struct s_apple
{
        int x_a;
        int y_a;
};

typedef struct s_apple posapp;

typedef struct maillon
{
	int x_m;
	int y_m;
	struct maillon * next;
};


void board(SDL_Renderer* renderer);
void applePosition(posapp  *apple);

#endif
