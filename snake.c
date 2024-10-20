#include "snake.h"

maillon *add_to_begin(maillon *list, int x, int y)
{
        maillon *new = (maillon*)malloc(sizeof(maillon));
        if (new == NULL)
        {
                printf("Erreur alloc\n");
                exit(1);
        }
        new->x_m = x;
        new->y_m = y;
        new->next = list;
        return new;
}

void move(maillon *list, int dir, int dir_n)
{
        maillon *current = list;
        int prev_x = list->x_m;
        int prev_y = list->y_m;
        int tempo_x;
        int tempo_y;

        if (dir_n == SDL_SCANCODE_O && dir!= SDL_SCANCODE_L )    //haut
        {
                list->y_m = (list->y_m)-32;
                current = current->next;
                while(current!=NULL)
                {
                        tempo_x = current->x_m;
                        tempo_y = current->y_m;
                        current->x_m = prev_x;
                        current->y_m = prev_y;
                        prev_x = tempo_x;
                        prev_y = tempo_y;
                        current = current->next;
                }
        }
	else if ( dir_n == SDL_SCANCODE_O)
        {
		list->y_m = (list->y_m)+32;
                current = current->next;
                while(current!=NULL)
                {
                        tempo_x = current->x_m;
                        tempo_y = current->y_m;
                        current->x_m = prev_x;
                        current->y_m = prev_y;
                        prev_x = tempo_x;
                        prev_y = tempo_y;
                        current = current->next;
                }
	}
	else if (dir_n ==  SDL_SCANCODE_L && dir != SDL_SCANCODE_O)    //bas
        {
                list->y_m = (list->y_m)+32;
                current = current->next;
                while(current!=NULL)
                {
                        tempo_x = current->x_m;
                        tempo_y = current->y_m;
                        current->x_m = prev_x;
                        current->y_m = prev_y;
                        prev_x = tempo_x;
                        prev_y = tempo_y;
                        current = current->next;
                }
        }
        else if (dir_n == SDL_SCANCODE_L)
        {
                list->y_m = (list->y_m)-32;
                current = current->next;
                while(current!=NULL)
                {
                        tempo_x = current->x_m;
                        tempo_y = current->y_m;
                        current->x_m = prev_x;
                        current->y_m = prev_y;
                        prev_x = tempo_x;
                        prev_y = tempo_y;
                        current = current->next;
                }

        }
        else if (dir_n == SDL_SCANCODE_K && dir != SDL_SCANCODE_P )    //gauche
        {
                list->x_m = (list->x_m)-32;
                current = current->next;
                while(current!=NULL)
                {
                        tempo_x = current->x_m;
                        tempo_y = current->y_m;
                        current->x_m = prev_x;
                        current->y_m = prev_y;
                        prev_x = tempo_x;
                        prev_y = tempo_y;
                        current = current->next;
                }
        }
        else if (dir_n == SDL_SCANCODE_K)
        {
                list->x_m = (list->x_m)+32;
                current = current->next;
                while(current!=NULL)
                {
                        tempo_x = current->x_m;
                        tempo_y = current->y_m;
                        current->x_m = prev_x;
                        current->y_m = prev_y;
                        prev_x = tempo_x;
                        prev_y = tempo_y;
                        current = current->next;
                }

        }
	else if (dir_n == SDL_SCANCODE_P && dir != SDL_SCANCODE_K )    //droit
        {
                list->x_m = (list->x_m)+32;
                current = current->next;
                while(current!=NULL)
                {
                        tempo_x = current->x_m;
                        tempo_y = current->y_m;
                        current->x_m = prev_x;
                        current->y_m = prev_y;
                        prev_x = tempo_x;
                        prev_y = tempo_y;
                        current = current->next;
                }
        }
        else if (dir_n == SDL_SCANCODE_P)
        {
                list->x_m = (list->x_m)-32;
                current = current->next;
                while(current!=NULL)
                {
                        tempo_x = current->x_m;
                        tempo_y = current->y_m;
                        current->x_m = prev_x;
                        current->y_m = prev_y;
                        prev_x = tempo_x;
                        prev_y = tempo_y;
                        current = current->next;
                }
        }
        else
        {
                printf("erreur\n");
        }
}

int S_Apple(maillon *list, posapp *apple)  // si serpent a mangé pomme
{
        if (list->x_m == apple->x_a && list->y_m == apple->y_a)
        {
        //      list->x_m = apple->x_a;
        //      list->y_m = apple->y_a;
                return 1;
        }
        return 0;
}
int collision(maillon *list)
{
        // serpent = mur
        if ( list->x_m <=160  || list->x_m >=640 || list->y_m <= 160 || list->y_m >=640)
        {
                printf("Perdu\n");
                return 1;
        }
        // serpent == serpent
        maillon *tmp = list->next;
        while (tmp != NULL)
        {
                if (list->x_m == tmp->x_m && list->y_m == tmp->y_m)
                {
                        printf("Perdu\n");
                        return 1;
                }
                tmp = tmp->next;
        }
        return 0;
}

