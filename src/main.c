#include "../inc/field.h"
#include "../inc/moving.h"
#include <assert.h>

/**
 *
 * make field
 * make snake
 * 	-linked list
 * 	-moving
 * make apple
 * @return
 */

void test();
void play();
void ExitGame();

int main(void)
{
	//test();
	initscr();  // Initialize the screen
	noecho();   // Don't echo any keypresses
	curs_set(FALSE); // Hide the cursor
	if(SnakeInit() != 0)
	{
		return (-1);
	}
	uint8_t h = 10;
	uint8_t w = 20;
	FieldSetSize(w, h);
	play(h,w);

	return (0);
}
void CheckGameOver(int h, int w)
{
	Snake *ptr = SnakeGetHead();
	if(ptr->h < 0 || ptr->w < 0)
	{
		ExitGame();
	}
	if(ptr->w > w || ptr->h > h )
	{
		ExitGame();
	}
}
void ExitGame()
{
    endwin(); // Clean up the window
    printf("Game Over!\n");
    exit(0);
}
void play(int h, int w)
{
	printf("%d,%d",h, w);
	Direction curDir = EAST;
	while(1)
	{
		clear();
		FieldDrawAll();
		refresh();
		usleep(500 * 1000);
		curDir = MovingReadInput(curDir);
		SnakeMove(curDir);
		CheckGameOver(h, w);
	}
}

void test_moving()
{
	int fd = open("test_moving.txt", O_RDONLY);
	if (fd == -1) {
		perror("Error opening test_input.txt");
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	Direction dir = EAST;
	Direction dirNew = MovingReadInput(dir);
	assert(dirNew == SOUTH);
	printf("dir: %d, dirNew: %d\n", dir, dirNew);
}
void test_field()
{
	char *temp = NULL;
	assert(FieldSetCharArray(temp) == -1);
	const char extra_width = 3;

	char arr[(10+2) * (10+extra_width)];
	assert(FieldSetCharArray(&arr[0]) == -1);

	FieldSetSize(10,10);
	assert(FieldSetCharArray(&arr[0]) == 0);

	SnakeSetCharArray(&arr[0]);
	printf("\r%s", arr);
}
void test_snake_init()
{
	assert(SnakeGetHead() == NULL);
	assert(SnakeInit() == 0);
	assert(SnakeGetHead() != NULL);
	assert(SnakeInit() == -1);

	printf("%s completed\n", __func__);
}
void test_snake_set_dir()
{
	SnakeSetDir(EAST);
	assert(SnakeGetHead()->dir == EAST);
	printf("%s completed\n", __func__);
}
void test_snake_update_dir()
{

	printf("%s completed\n", __func__);

}
void test_snake_move()
{
	int wHead = SnakeGetHead()->w;
	Snake* till = SnakeGetHead()->next;
	int wTill = till->w;

	assert(SnakeMove(EAST) == 0);
	assert(SnakeGetHead()->dir == EAST);
	assert(SnakeGetHead()->w == wHead+1);
	assert(till->w == wTill+1);
	assert(till->dir == EAST);
	if(SnakeAdd() == -1)
	{
		fprintf(stdout, "snake add -1\n");
	}
	SnakePrint();

	assert(till->next->w == wTill);

	printf("%s completed\n", __func__);
}
void test()
{
	test_snake_init();
	test_snake_set_dir();
	test_snake_update_dir();
	test_snake_move();
	test_moving();
	test_field();
	printf("%s completed\n", __func__);
	exit(0);
}
