/*
* File Name     : 170877_harsh_DR_module1_T006_1-13.c
* Description   : Write a program to print a histogram of the lengths of words in its input.
		  It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
* Author        : harsh_kerai
* Created       : 10-02-2026
*/

#include<stdio.h>
#include"header.h"
#include<stdlib.h>

void print_a_histogram(void)
{

int c;
int wc=0;
int state=0;

	while((c=getchar()) != EOF)
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

int index = 0, len = 0;
state = 0;
int max_len = 0;

	while((c = getchar()) != EOF)
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

int *histogram = calloc(max_len + 1, sizeof(int));
int count=0;
int highest_count=0;

	for(int i = 0;i<wc;i++)
	{
	histogram[words[i]]++;
	}

printf("horizontal histogram---------------------------------\n");
	for(int i = 0;i<=max_len;i++)
	{
		if(histogram[i] != 0)
		{
		count=histogram[i];

		if(count>highest_count)
		highest_count=count;

		printf(" %d :",i);
			while(count>0)
			{
			printf(" * ");
			count--;
			}
		printf("\n");
		}

		else{
		continue;
		}
	}

printf("\nvertical histogram--------------------------------\n");
	for (int row = highest_count; row >0; row--)
	{
		for (int col = 0; col <=max_len; col++)
		{
		 if(histogram[col] == 0)
		 continue;

		 if (histogram[col] >= row)
		 printf(" * ");

		 else
		 printf("   ");
		}
	printf("\n");
	}
	for(int col = 0;col<=max_len;col++)
	{
		if(histogram[col] !=0)
		printf(" %d ",col);
	}
	printf("\n");

free(words);
free(histogram);
}

