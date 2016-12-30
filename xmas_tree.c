#include <stdio.h>
#include <stdlib.h>

/*
	Author:		Eddie N. <en@sector572.com>
	Date:		2016-12-30
	Filename:	xmas_tree.c
	Version:	0.1.0
	Description:	This program accepts an integer and draws an ascii tree
			on the console.
*/

void printTree(int size);
void printSpaces(int length);

int main(int argc, char* argv[])
{
	int rtn = 0;
	int size = 7;
	int sizeTmp = 0;
	int minSize = 5;
	int maxSize = 31;
	int tmp = 0;

	if(argc == 2)
	{
		sizeTmp = atoi(argv[1]);

		if(sizeTmp >= minSize && sizeTmp <= maxSize)
		{
			tmp = sizeTmp - 1;

			if(tmp % 2 == 0)
			{
				size = sizeTmp;
			}
			else
			{
				fprintf(stderr,
					"The size %d is not valid. Examples include: 5, 7, 9, 11, etc.\n",
					sizeTmp);
				rtn = 1;
			}
		}
		else
		{
			fprintf(stderr,
				"The size must be a valid integer between %d and %d.\n",
				minSize,
				maxSize);
			rtn = 1;
		}
	}

	if(!rtn)
	{
		printTree(size);
	}

	return rtn;
}

void printTree(int size)
{
	int i, j, s, m, t;
	int offset = 10;

	i=j=s=m=0;

	m = (size - 1) / 2;
	t = m;

	printf("\n");

	for(i = 0; i < size; i += 2)
	{
		printSpaces(offset);
		printSpaces(m);

		for(j = 0; j < i + 1; j++)
		{
			printf("*");
		}

		printf("\n");
		m--;
	}

	printSpaces(offset);
	printSpaces(t);

	printf("|\n");
	printf("\n");
}

void printSpaces(int length)
{
	int i = 0;

	for(i = 0; i < length; i++)
	{
		printf(" ");
	}
}
