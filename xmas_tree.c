/*
Copyright 2016 Eddie N. <en@sector572.com>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

/*
	Author:		Eddie N. <en@sector572.com>
	Date:		2016-12-30
	Filename:	xmas_tree.c
	Version:	0.2.0
	Description:	This program accepts an integer and draws an ascii tree
			on the console.
*/

void printTree(int size, int offset);
void printSpaces(int length);
void printBranch(int spaces, int length);
void printTrunk(int spaces, int length);

int main(int argc, char* argv[])
{
	int rtn = 0;
	int size = 7;
	int sizeTmp = 0;
	int minSize = 5;
	int maxSize = 31;
	int offset = 10;
	int tmp = 0;
	unsigned short columns = 80;
	struct winsize wSz;
	unsigned short halfSize = 0;

	if(ioctl(0, TIOCGWINSZ, &wSz) == 0)
	{
		columns = wSz.ws_col;
	}

	/* Determine terminal column mid point. */

/*	if(columns % 2 == 0)
	{
		halfSize = columns / 2 - 1;
	}
	else
	{
		halfSize = (columns - 1) / 2 - 1;
	}
*/
	halfSize = columns / 2;

	#ifdef _DEBUG_
	printf("Columns: %d\n", columns);
	printf("Column Midpoint: %d\n", halfSize);
	#endif

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
		/* Calculate white space offset. */
		offset = halfSize - (size / 2) - 1;

		#ifdef _DEBUG_
		printf("Tree size: %d\n", size);
		printf("Offset: %d\n", offset);
		#endif

		printTree(size, offset);
	}

	return rtn;
}

void printTree(int size, int offset)
{
	int i, j, s, m, t;

	i=j=s=m=0;

	m = (size - 1) / 2;
	t = m;

	printf("\n");

	for(i = 0; i < size; i += 2)
	{
		printBranch(offset + m,
			    i + 1);
		m--;
	}

	printTrunk(offset + t, 1);

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

void printBranch(int spaces, int length)
{
	int i = 0;

	printSpaces(spaces);

	for(i = 0; i < length; i++)
	{
		printf("*");
	}

	printf("\n");
}

void printTrunk(int spaces, int length)
{
	int i = 0;

	printSpaces(spaces);

	for(i = 0; i < length; i++)
	{
		printf("|\n");
	}
}
