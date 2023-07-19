/*
 * field.h
 *
 *  Created on: Jul 14, 2023
 *      Author: olav
 */

#ifndef FIELD_H_
#define FIELD_H_

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


#endif /* FIELD_H_ */
