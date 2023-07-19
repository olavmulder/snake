/*
 * field.h
 *
 *  created on: jul 14, 2023
 *      author: olav
 */

#ifndef field_h_
#define field_h_

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <ncurses.h>

#include "snake.h"



int FieldDrawAll();
void FieldSetSize(uint8_t w, uint8_t h);
int FieldSetCharArray(char *arr);


#endif /* field_h_ */
