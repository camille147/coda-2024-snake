#include "snake.h"

void add_to_begin(maillon **list, int x, int y)
{
	maillon *new = (maillon*)malloc(sizeof(maillon));
	if (new == NULL)
	{
		printf("Erreur alloc\n");
		exit(1);
	}
	new->x = x;
	new->y = y;
	new->next = *list;
	*list = new;
}

void move(maillon *list, int dir)
{
	maillon *current = list;
	int prev_x = list->x;
	int prev_y = list->y;
	int tempo_x;
	int tempo_y;

	if (dir == )    //haut
	{
		list->y = (list->y)-1;
		current = current->next;
		while(current!=NULL)
		{
			tempo_x = current->x;
			tempo_y = current->y;
			current->x = prev_x;
			current->y = prev_y;
			prev_x = temp_x;
			prev_y = temp_y;
			current = current->next;
		}
	}

	else if (dir == )    //bas
        {
                list->y = (list->y)+1;
                current = current->next;
                while(current!=NULL)
                {
                        tempo_x = current->x;
                        tempo_y = current->y;
                        current->x = prev_x;
                        current->y = prev_y;
                        prev_x = temp_x;
                        prev_y = temp_y;
                        current = current->next;
                }
        }
	else if (dir == )    //gauche
        {
                list->x = (list->x)-1;
                current = current->next;
                while(current!=NULL)
                {
                        tempo_x = current->x;
                        tempo_y = current->y;
                        current->x = prev_x;
                        current->y = prev_y;
                        prev_x = temp_x;
                        prev_y = temp_y;
                        current = current->next;
                }
        }
	else (dir == )    //droit
        {
                list->x = (list->x)+1;
                current = current->next;
                while(current!=NULL)
                {
                        tempo_x = current->x;
                        tempo_y = current->y;
                        current->x = prev_x;
                        current->y = prev_y;
                        prev_x = temp_x;
                        prev_y = temp_y;
                        current = current->next;
                }
        }
}
