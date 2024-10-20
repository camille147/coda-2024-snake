#include "snake.h"

int main()
{

	posapp *apple = malloc(sizeof(posapp));
	int dir; // = SDL_SCANCODE_P;
	int dir_n;
	int nb_apple = 0;
	maillon *snake = malloc(sizeof(maillon));
	snake->x_m = 384;
	snake->y_m = 608;
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

	SDL_Surface* surface1 = IMG_Load("serpent.png");
	if (surface1 == NULL)
	{
		printf("Error loading image 1 %s\n", IMG_GetError());
		return 1;
	}
	SDL_Texture* texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
	if (texture1 == NULL)
	{
		printf("Error creating texture1\n");
		return 1;
	}

	SDL_FreeSurface(surface);
	SDL_FreeSurface(surface1);

//	snake = add_to_begin(snake,400, 640);
	applePosition(apple);
	SDL_Rect serpent = {snake->x_m, snake->y_m, 32, 32};
	SDL_Rect pomme = {apple->x_a, apple->y_a, 32, 32};
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
			else if (e.type == SDL_KEYDOWN)
			{
				dir = dir_n;
				dir_n = e.key.keysym.scancode;
			}
		}
		//applePosition(apple);
		//SDL_Rect pomme = {apple->x_a, apple->y_a, 16, 16};

		move(snake, dir, dir_n);
		serpent.x = snake->x_m;
		serpent.y = snake->y_m;
		if (collision(snake))
		{
			quit = 1;
		}
		if (S_Apple(snake, apple))
		{
			nb_apple = nb_apple+1;
			snake = add_to_begin(snake, apple->x_a, apple->y_a);
			applePosition(apple);
			pomme.x = apple->x_a;
			pomme.y = apple->y_a;
			SDL_Rect pomme = {apple->x_a, apple->y_a, 32, 32};
			if (nb_apple>=30)
			{
				printf("VICTORY\n");
				quit = 1;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		board(renderer);
		SDL_RenderCopy(renderer, texture, NULL, &pomme);

		maillon *current = snake;
		while (current != NULL)
		{
			SDL_Rect serpent = {current->x_m, current->y_m, 32, 32};
			SDL_RenderCopy(renderer, texture1, NULL, &serpent);
			current = current->next;
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}
	maillon *tmp = snake;
	while (tmp != NULL)
	{
		maillon *next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(apple);
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
    	SDL_DestroyWindow(window);
    	IMG_Quit();
    	SDL_Quit();
	return 0;
}
