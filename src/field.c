#include "../inc/field.h"


static uint8_t width = 0, height = 0;

void FieldSetSize(uint8_t w, uint8_t h)
{
	width = w;
	height = h;
}

int FieldDraw()
{
	if(width == 0 || height == 0)
		return (-1);

	for(uint8_t i = 0; i < width; i++)
	{
		for(uint8_t j = 0; j < height; j++)
		{
			printf("x");
		}
		printf("\n");
	}
	return (0);
}
