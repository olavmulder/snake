#include "../inc/field.h"


uint8_t width = 0;
uint8_t height = 0;
const char extra_width = 3;
void FieldSetSize(uint8_t w, uint8_t h)
{
	width = w;
	height = h;
}

int FieldSetCharArray(char *arr)
{
	if(width == 0 || height == 0 || arr == NULL)
			return (-1);

	for(uint8_t i = 0; i < height+2; i++)
	{
		for(uint8_t j = 0; j < width+extra_width; j++)
		{

			//last one in row
			if(j == width+extra_width - 1)
			{
				*(arr+(i*(width+extra_width) +j)) = (char)'\n';
			}
			//size wall & upper & lower side
			else if ((i == 0 || i == height +1) ||
					(j == 1 || j == width +extra_width -2))
			{
				*(arr+(i*(width+extra_width) +j)) = (char)'x';
			}
			//inner space
			else
			{
				*(arr+(i*(width+extra_width) +j)) = (char)' ';
			}
		}
	}
	*(arr+( (height+2) * (width+extra_width))-1) = '\0';
	return (0);
}
int FieldDrawAll()
{


	if(height == 0 || width == 0)
	{
		fprintf(stdout, "width == 0 || height == 0");
		return (-1);
	}
	char arr[(height+2) * (width+extra_width)];

	if(FieldSetCharArray(&arr[0])  == -1)
	{
		fprintf(stdout, "error FieldSetCharArray\n");
		return (-1);
	}
	SnakeSetCharArray(&arr[0]);
	mvprintw(0,0, "%s", arr);
	fflush(stdout);
	return (0);
}
