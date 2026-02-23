/*
* File Name     : 170904_harsh_DR_module1_T006_1-17.c
* Description   : Write a program to print all input lines that are longer than 8 characters.
* Author        : harsh_kerai
* Created       : 11-02-2026
*/
#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include "header.h"

#define MAXLINE 1000

void longer_than_8_characters(void)
{
char line[MAXLINE];
char long_line[MAXLINE]="";
int8_t state=1;
        while (fgets(line, sizeof(line), stdin) != NULL) {
                int32_t len = strlen(line);

	for(int8_t i=0;line[i] != '\0';i++)
	{
		 if(line[i]<33){
		 state = 0;
		 }
		 else{
		 state = 1;
		 break;
		 }
	}
        if (len > 8 && state == 1) {
	strcat(long_line,line);
          }
        }
	if(strlen(long_line) > 0){
	printf("Line longer than 8 characters:\n%s",long_line);
	}
}
