#include "../inc/moving.h"
#define SPEED 200

Direction MovingReadInput(Direction dir)
{
	int c;
	c = GetCharWithTimeout(SPEED);
	switch(c)
	{
	case 'w':
		dir = NORTH;
		break;
	case 'd':
		dir = EAST;
		break;
	case 's':
		dir = SOUTH;
		break;
	case 'a':
		dir = WEST;
		break;
	default:
		break;
	}
	if(SnakeMove(dir) != 0)
	{
		fprintf(stdout, "SnakeMove error\n");
	}
	return (dir);
}

int GetCharWithTimeout(int timeoutMillis)
{
    fd_set rfds;
    struct timeval tv;
    int retval;

    FD_ZERO(&rfds);
    FD_SET(STDIN_FILENO, &rfds);

    tv.tv_sec = timeoutMillis / 1000;
    tv.tv_usec = (timeoutMillis % 1000) * 1000;

    retval = select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv);
    if (retval == -1) {
        perror("select()");
        return EOF;
    } else if (retval == 0) {
        // Timeout occurred
        return EOF;
    } else {
        return (getchar());
    }
}
