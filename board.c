#include "snake.h"

void board(SDL_Renderer* renderer)
{
	//plateau total (mur + jeu)
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	int pla_x = 100;
	int pla_y = 100;

	//murs
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	//mur du haut
	SDL_Rect m_h = { pla_x, pla_y, 600, 60 };
	SDL_RenderFillRect(renderer, &m_h);

	//mur du bas
	SDL_Rect m_b = { pla_x, 640, 600, 60 };
        SDL_RenderFillRect(renderer, &m_b);

	//mur du gauche
        SDL_Rect m_g = { pla_x, pla_y, 60, 600 };
        SDL_RenderFillRect(renderer, &m_g);

	//mur du droit
        SDL_Rect m_d = { 640, pla_y, 60, 600 };
        SDL_RenderFillRect(renderer, &m_d);

	// jeu
	SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255);

	SDL_Rect jeu = { 160,160 , 480, 480};
	SDL_RenderFillRect(renderer, &jeu);


	//affichage
//	SDL_RenderPresent(renderer);
}
