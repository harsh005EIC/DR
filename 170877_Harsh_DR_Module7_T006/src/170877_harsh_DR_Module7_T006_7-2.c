/*
* File Name     : 170877_harsh_DR_module7_T006_7-2.c
* Description   : Write a program that will print arbitrary input in a sensible way. As a minimum, it should print non-graphic
		  characters in octal or hexadecimal according to local custom and break long text lines.
* Author        : harsh_kerai
* Date          : 21/04/2025
*/

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>

#define MAXLINE 1000

	void print_non_graphic_characters(void)
	{
		int8_t col = 0;
		char str[100]="";
		char main_str[MAXLINE]="";

		while(fgets(str,sizeof(str),stdin) != NULL)
		{
			strcat(main_str,str);
		}
			for(int8_t i=0;main_str[i] != '\0';i++)
			{
				if(isprint(main_str[i]))
				{
					putchar(main_str[i]);
					col++;
				}
				else
				{
					printf("[x%02X | %4o]", (unsigned char)main_str[i],  (unsigned char)main_str[i]);
					col += 8;
				}

				if(col >= MAXLINE)
                        	{
                                	putchar('\n');
                                	col = 0;
                        	}
			}
		return;
	}
