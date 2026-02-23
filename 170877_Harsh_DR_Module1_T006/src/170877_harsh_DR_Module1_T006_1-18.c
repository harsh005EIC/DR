/*
* File Name     : 170904_harsh_DR_module1_T006_1-18.c
* Description   : Write a program to remove trailing blanks and tabs from each line of input,
		  and to delete entirely blank lines.
* Author        : harsh_kerai
* Created       : 11-02-2026
*/

#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include "header.h"

#define MAXLINE 1000
void remove_trailing_blanks_and_tabs(void)
{
int32_t len=0;
char line[MAXLINE];
	while(fgets(line, sizeof(line), stdin) != NULL){
	len=strlen(line);
	 if (line[len-1] == '\n')
		{
		  line[--len]='\0';
		}
	 while (len > 0 && (line[len - 1] == ' ' || line[len-1] == '\t'))
	 {
                line[--len] = '\0';
         }
		if (len > 0) {
                printf("%s",line);
        	}
	}
}

