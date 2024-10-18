#include "snake.h"

void applePosition(posapp  *apple)
{
	srand(time(NULL));
	int cas_x = 1 + rand() % 29 ;
    	int cas_y = 1 + rand() % 29 ;
	apple->x_a = 160 + 16 * cas_x;
	apple->y_a = 160 + 16 * cas_y;
	printf("apple: %d, %d\n", apple->x_a, apple->y_a);
}
