/*
 * moving.h
 *
 *  Created on: Jul 16, 2023
 *      Author: olav
 */

#ifndef INC_MOVING_H_
#define INC_MOVING_H_
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

#include "snake.h"

Direction MovingReadInput(Direction dir);
int GetCharWithTimeout(int timeoutMillis);




#endif /* INC_MOVING_H_ */
