/*
* File Name     : 170904_harsh_DR_module1_T006_1-9.c
* Description   : Write a program to copy its input to its output,
		  replacing each string of one or more blanks by a single blank.
* Author        : harsh_kerai
* Created       : 06-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include "header.h"

void remove_blanks_by_one(void)
{
int16_t c;
int32_t blank=0;

	while((c=getchar()) != EOF)
	{
		if(c == ' ')
		{
		 if(!blank)
		  {
			putchar(c);
			blank=1;
		  }
		}
		else if( c == '\t')
		 {
			continue;
		 }
		else
		{
		 putchar(c);
		 blank=0;
		}
	}
}
