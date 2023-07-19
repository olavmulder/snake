/*
 * apple.c
 *
 *  Created on: Jul 19, 2023
 *      Author: olav
 */
#include "../inc/apple.h"
#include <time.h>
#include <stdbool.h>

static volatile bool isAppleSet = false;
static int apple_w = -1;
static int apple_h = -1;
static unsigned int score = 0;

unsigned int GetScore()
{
	return score;
}
void AppleIsFound()
{

	isAppleSet = false;
	apple_w = -1;
	apple_h = -1;
	score++;
	if(SnakeAdd() != 0)
	{
		fprintf(stderr, "SnakeADd error in %s\n", __func__);
		ExitGame();
	}
}
void AppleSetLocation()
{
	if(!isAppleSet)
	{
		isAppleSet = true;

		uint8_t max_h = height;
		uint8_t max_y = width;

		srand((unsigned int)time(0));
		apple_w = rand()%max_y;
		apple_h = rand()%max_h;
		apple_w +=1;
		apple_h +=1;

		//boarder fix

	}
}

void AppleDraw(char* arr)
{
	AppleSetLocation();
	*(arr+(apple_h*(width+3) + apple_w)) = 'A';
}

/**
 * chech on values -1 if not set
 * @param w
 * @param h
 */
void AppleGetLocation(int *w, int *h)
{
	*w = apple_w;
	*h = apple_h;
}
