/*
* File Name     : 170904_harsh_DR_module1_T006_1-20.c
* Description   : Write a program detab that replaces tabs in the input with the proper number of blanks to space to the
		  next tab stop.
		  Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
* Author        : harsh_kerai
* Created       : 11-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include "header.h"

void detab(void){
int16_t c;
int8_t space;
int8_t tab=8;
int16_t character=0;
while((c=getchar()) != EOF)
{
	if(c == '\t')
	{
	space = tab - (character % tab);
	for(int8_t i=0;i<space;i++){
	 putchar('*');
	}
	character=character+space;
	}

	else
	{
	 putchar(c);
		if(c=='\n')
		{
		character=0;
		}
		else
		character++;
	}
}

}
