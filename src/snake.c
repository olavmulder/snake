#include "../inc/snake.h"


static Snake *snake_head = NULL;
static Snake *snake_till = NULL;

Snake * SnakeGetHead() {
	return (snake_head);
}
int SnakeInit()
{
	if(snake_head != NULL || snake_till != NULL)
		return (-1);

	snake_head = (Snake*)malloc(sizeof(Snake));
	snake_till = (Snake*)malloc(sizeof(Snake));
	if(snake_head == NULL || snake_till == NULL)
		return (-1);

	snake_head->prev = NULL;
	snake_head->next = snake_till;
	snake_head->h = 0;
	snake_head->w = 1;
	SnakeSetDir(EAST);

	snake_till->h = 0;
	snake_till->w = 0;
	snake_till->prev = snake_head;
	snake_till->next = NULL;
	snake_till->dir = snake_till->prev->dir;
	return (0);
}
void SnakeSetDir(Direction dir)
{
	snake_head->dir = dir;
}
int SnakeUpdateDir()
{
	Snake *ptr = snake_till;
	if(ptr == NULL)
		return(-1);
	while(ptr != NULL)
	{
		if(ptr->prev != NULL)
			ptr->dir = ptr->prev->dir;
		ptr = ptr->prev;
	}
	return (0);
}
int SnakeMove(Direction dir)
{
	Snake* ptr = snake_head;
	if(ptr == NULL)
	{
		perror("no snake head");
		return (-1);
	}
	SnakeSetDir(dir);
	while(ptr != NULL)
	{
		if(SnakeUpdatePosition(ptr->dir, ptr) == -1)
		{
			fprintf(stdout, "SnakeUpdatePosition return -1\n");
			return (-1);
		}
		ptr = ptr->next;
	}
	SnakeUpdateDir();
	while(ptr)
	printf("\n\n");
	return (0);
}

int SnakeGetLength()
{
	if(snake_head == NULL)
		return (-1);
	Snake* ptr = snake_head;
	int len = 0;
	while(ptr != NULL)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}
/**
 * oposite direction of till
 * @return
 */
int SnakeAdd()
{
	Snake *new = (Snake*)malloc(sizeof(Snake));
	if(new == NULL)
	{
		return (-1);
	}
	Direction dir = SnakeGetOpositeDirection(snake_till->dir);
	new->w = snake_till->w;
	new->h = snake_till->h;
	if(SnakeUpdatePosition(dir, new) == -1)
	{
		fprintf(stdout, "%s, can't update position\n", __func__);
		return (-1);
	}
	if(SnakeIsPositionTaken(new->w, new->h) == 0)
	{
		fprintf(stdout, "snake position(%d, %d) is taken", new->w,new->h);
		return (-1);

	}
	printf("new->w = %d, new->h = %d\n", new->w, new->h);
	snake_till->next = new;
	new->prev = snake_till;
	new->next = NULL;
	new->dir = snake_till->dir;
	snake_till = new;
	return (0);

}
Direction SnakeGetOpositeDirection(Direction dir)
{
	switch(dir)
	{
	case NORTH:
		return (SOUTH);
		break;
	case EAST:
		return (WEST);
		break;
	case SOUTH:
		return (NORTH);
		break;
	case WEST:
		return (EAST);
		break;
	default:
		exit(0);
	}

}
int SnakeIsPositionTaken(uint8_t w, uint8_t h)
{
	Snake *ptr = snake_head;
	while(ptr != NULL)
	{
		if(ptr->h == h && ptr->w == w)
			return (0);
		ptr = ptr->next;
	}
	return (-1);
}
int SnakeUpdatePosition(Direction dir, Snake* new)
{
	if(new == NULL)
		return (-1);
	switch(dir)
		{
		case NORTH:
			new->h++;
			break;
		case EAST:
			new->w++;
			break;
		case SOUTH:
			new->h--;
			break;
		case WEST:
			new->w--;
			break;
		default:
			return (-1);
			break;
		};
	return (0);
}

void SnakePrint()
{
	Snake * ptr = snake_head;
	printf("print snake:\n");
	while(ptr != NULL)
	{
		printf("w: %d, h: %d, dir: %d\n", ptr->w, ptr->h, ptr->dir);
		ptr = ptr->next;
	}
	printf("print snake end\n");

}
