/*
 * apple.h
 *
 *  Created on: Jul 19, 2023
 *      Author: olav
 */

#ifndef INC_APPLE_H_
#define INC_APPLE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
/*from field.c*/
extern uint8_t width;
extern uint8_t height;

unsigned int GetScore();
void AppleIsFound();
void AppleSetLocation();
void AppleDraw(char* arr);
void AppleGetLocation(int *w, int *h);

extern int SnakeAdd();

extern void ExitGame();
#endif /* INC_APPLE_H_ */
