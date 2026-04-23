/*
* File Name     : 170877_harsh_DR_module7_T006_7-1.c
* Description   : Write a program that converts upper case to lower or lower case to upper, depending on the name it is
		  invoked with, as found in argv[0].
* Author        : harsh_kerai
* Date          : 21/04/2025
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

	void upper_lower(int argc, char *argv[])
	{
		int16_t c;
		int8_t tolower_flag = 0;
		int8_t toupper_flag = 0;

		if(strstr(argv[1], "lower") != NULL)
			tolower_flag = 1;
		else if(strstr(argv[1], "upper") != NULL)
			toupper_flag = 1;
		else
		{
			printf("Unknown program name: use 'lower' or 'upper'\n");
			return;
		}

		while((c = getchar()) != EOF)
		{
			if(tolower_flag)
				putchar(tolower(c));
			else if(toupper_flag)
				putchar(toupper(c));
		}

		return;
	}
