/*
* File Name     : 170877_harsh_DR_module1_T006_1-12.c
* Description   : Write a program that prints its input one word per line
* Author        : harsh_kerai
* Created       : 09-02-2026
*/

#include<stdio.h>
#include "header.h"
#include<stdint.h>
void one_word_per_line(void)
{
int16_t c;
int8_t state=1;

	while((c=getchar()) != EOF)
	{
	  if( c == ' ' || c == '\t')
		{
		 if(!state)
		  {
			printf("\n");
			state=1;
		  }
		}
	  else
		{
		putchar(c);
		state=0;
		}
	}
}
