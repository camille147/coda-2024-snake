#include "snake.h"


int main()
{

	posapp *apple = malloc(sizeof(posapp));;


        if (SDL_Init(SDL_INIT_VIDEO )< 0)
        {
                printf("Error SDL2 Init : %s\n", SDL_GetError());
                return 1;
        }

        SDL_Window* window = SDL_CreateWindow("snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800 ,800 , SDL_WINDOW_OPENGL);
        if (window == NULL)
        {
                printf("Error Window Creation\n");
                return 3;
        }


        if (IMG_Init(IMG_INIT_PNG) == 0)
        {
                printf("Erreur d'initialisation de la SDL_Image\n");
                return 1;
        }


        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == NULL)
        {
                printf("Erreur à la création du renderer\n");
                return 1;
        }

        SDL_Surface* surface = IMG_Load("pomme.png");
        if (surface == NULL)
        {
                printf("Error loading image %s\n", IMG_GetError());
                return 1;
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == NULL)
        {
                printf("Error creating texture\n");
                return 1;
        }
	SDL_FreeSurface(surface);

	int quit = 0;
	SDL_Event e;

	while (quit!=1)
	{
		while (SDL_PollEvent(&e))
                {
                        if (e.type == SDL_QUIT)
                        {
                                quit = 1;
                        }
		}
		applePosition(apple);
		SDL_Rect pomme = {apple->x_a, apple->y_a, 16, 16};

		board(renderer);
		SDL_RenderCopy(renderer, texture, NULL, &pomme);
		SDL_RenderPresent(renderer);
	}
	free(apple);
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
    	SDL_DestroyWindow(window);
    	IMG_Quit();
    	SDL_Quit();

    	return 0;
}
