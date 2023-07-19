/*
 * snake.h
 *
 *  Created on: Jul 14, 2023
 *      Author: olav
 */

#ifndef INC_SNAKE_H_
#define INC_SNAKE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef enum _direction
{
	NORTH, EAST, SOUTH, WEST
}Direction;

typedef struct _snake
{
	int w;
	int h;
	Direction dir;
	struct _snake *prev;
	struct _snake *next;
}Snake;

/*from field.c*/
extern uint8_t width;
extern uint8_t height;

extern void ExitGame();

int SnakeInit();
int SnakeMove(Direction dir);
void SnakeSetCharArray(char* arr);
int SnakeAdd();
void SnakeSetDir(Direction dir);
Snake* SnakeGetHead();
int SnakeGetLength();
int SnakeIsPositionTaken(int w, int h);
int SnakeUpdateDir();
int SnakeUpdatePosition(Direction dir, Snake* new);
Direction SnakeGetOpositeDirection(Direction dir);

//debug
void SnakePrint();
#endif /* INC_SNAKE_H_ */
