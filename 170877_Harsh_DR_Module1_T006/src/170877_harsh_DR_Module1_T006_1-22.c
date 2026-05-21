/*
* File Name     : 170877_harsh_DR_module1_T006_1-22.c
* Description   : Write a program to ``fold'' long input lines into two or more shorter lines after the last
		  non-blank character that occurs before the n-th column of input. Make sure your program
		  does something intelligent with very long lines, and if there are no blanks or tabs before
		  the specified column
* Author        : harsh_kerai
* Created       : 12-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "header.h"

#define maxline 1000

void fold(void)
{
int16_t c;
int8_t fold;
char line[maxline];
int8_t col = 0;
int i = 0;

printf("After how much character you want to fold : ");
scanf("%hhd",&fold);
getchar();

int last_blank = -1;

	while ((c = getchar()) != EOF){

		line[i++] = c;
		col++;

		if (c == ' ' || c == '\t'){
		last_blank = i - 1;
		}

		if (c == '\n'){
			fwrite(line,1,i,stdout);
			col=0;
			i = 0;
			last_blank = -1;
		continue;
		}


		if (col >= fold){

			if (last_blank != -1){
			fwrite(line, 1, last_blank, stdout);
			putchar('\n');

			i=i-last_blank-1;
			for (int j = 0; j < i; j++)
			line[j] = line[last_blank + 1 + j];
			}

			else{
			fwrite(line,1,i,stdout);
			putchar('\n');
			i=0;
			}

		col = i;
		last_blank = -1;
		}

		if (i >= maxline - 1)
		{
		fwrite(line,1,i,stdout);
		i = 0;
		col = 0;
		last_blank = -1;
        	}
	}

		if (i > 0){
                fwrite(line, 1, i, stdout);
                }
}


