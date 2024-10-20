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

typedef struct s_maillon
{
	int x_m;
	int y_m;
	struct s_maillon * next;
}maillon;


void board(SDL_Renderer* renderer);
void applePosition(posapp  *apple);
maillon *add_to_begin(maillon *list, int x, int y);
void move(maillon *list, int dir, int dir_n);
int S_Apple(maillon *list, posapp *apple);
int collision(maillon *list);
#endif
