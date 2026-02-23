/*
* File Name     : 170904_harsh_DR_module1_T006_1-13.c
* Description   : Write a program to print a histogram of the lengths of words in its input.
		  It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
* Author        : harsh_kerai
* Created       : 10-02-2026
*/

#include<stdio.h>
#include "header.h"
#include <stdlib.h>
/*void print_a_histogram(void)
{
int16_t c;
int8_t state=1;

        while((c=getchar()) != EOF)
        {
          if( c == ' ' || c == '\t' ||  c == '\n')
                {
                 if(!state)
                  {
                        printf("\n");
                        state=1;
                  }
                }
          else
                {
                printf("*");
                state=0;
                }
        }
}
*/
void print_a_histogram(void)
{
int16_t c;
int32_t wc=0;
int8_t state=0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
		state = 0;
		}
		else if (!state)
		{
		state = 1;
		wc++;
		}
	}

int *words=malloc(wc*sizeof(int));

	rewind(stdin);

int8_t index = 0, len = 0;
state = 0;
int32_t max_len = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
		if (state)
		 {
		words[index++] = len;
			if (len > max_len)
			max_len = len;
		len = 0;
		state = 0;
		 }
		}

		else
		{
		state = 1;
		len++;
		}
	}


	for (int16_t row = max_len; row > 0; row--)
	{
		for (int16_t col = 0; col < wc; col++)
		{
		 if (words[col] >= row)
		 printf(" * ");
		 else
		 printf("   ");
		}
	printf("\n");
	}

    free(words);
}
