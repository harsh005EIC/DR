/*
* File Name     : 170877_harsh_DR_module1_T006_1-8.c
* Description   : Write a program to count blanks, tabs, and newlines.
* Author        : harsh_kerai
* Created       : 06-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include "header.h"

void count_bl_t_nl(void)
{
int16_t c;
int32_t blanks=0,tabs=0,newlines=0;

	while((c=getchar()) != EOF)
		{

			if ( c == ' ')
			 blanks++;
			else if( c == '\t')
			 tabs++;
			else if( c == '\n')
			 newlines++;
		}

	printf("Total Blanks = %d\n",blanks);
	printf("Total tabs = %d\n",tabs);
	printf("Total newlines = %d\n",newlines);
}

