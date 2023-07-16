#include "../inc/field.h"
#include "../inc/snake.h"
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

int main(void)
{
	test();

	uint8_t h = 10;
	uint8_t w = 10;
	FieldSetSize(w, h);

	if(FieldDraw() < 0)
	{
		return (0);
	}

	return (0);
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

	printf("%s completed\n", __func__);
	exit(0);
}
