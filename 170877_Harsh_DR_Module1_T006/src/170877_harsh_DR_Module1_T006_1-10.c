/*
* File Name     : 170877_harsh_DR_module1_T006_1-10.c
* Description   : Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b,
		  and each backslash by \\. This 
		  makes tabs and backspaces visible in an unambiguous way.
* Author        : harsh_kerai
* Created       : 06-02-2026
*/
#include<stdio.h>
#include "header.h"
#include<stdint.h>

void replace_blankspace_t_n_b(void)
{
int c;



	while( (c=getchar()) != EOF )
	 {
	  if( c == ' ' )
		{
		 putchar('\\');
		 putchar('b');
		}
	  else if( c == '\t')
		{
		 putchar('\\');
		 putchar('t');
		}
	  else if( c == '\\')
		{
		 putchar('\\');
		 putchar('\\');
		}
	  else
		{
		 putchar(c);
		}
	 }
}
