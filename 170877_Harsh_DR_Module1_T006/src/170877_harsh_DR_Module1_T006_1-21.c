/*
* File Name     : 170904_harsh_DR_module1_T006_1-21.c
* Description   : Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks
		  to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single
		  blank would suffice to reach a tab stop, which should be given preference?
* Author        : harsh_kerai
* Created       : 11-02-2026
*/

#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include "header.h"

void entab(void){
int16_t c;
int8_t space=0;
int8_t tab=8;
int8_t character=0;

	while((c=getchar()) != EOF)
	{
	 if(c == ' ')
	  {
	   space++;
	   character++;
		if(character % tab == 0)
		{
		 putchar('\\');
		 putchar('t');
		 space=0;
		}
	  }

	else
	   {
	     while(space > 0)
		{
		  putchar('*');
		  space--;
		}
	     putchar(c);
		if(c=='\n')
		{
		character=0;
		}
		else
		{
		  character++;
		}
	   }
	}
}

