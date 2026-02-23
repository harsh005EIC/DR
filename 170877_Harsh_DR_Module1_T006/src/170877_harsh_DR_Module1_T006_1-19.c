/*
* File Name     : 170904_harsh_DR_module1_T006_1-19.c
* Description   : Write a function reverse(s) that reverses the character string s.
		  Use it to write a program that reverses its input a line at a time.
* Author        : harsh_kerai
* Created       : 11-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "header.h"

#define SIZE 1000
void reverses_the_character_string_s(void)
{
char line[SIZE];
int16_t len;

while(fgets(line,sizeof(line),stdin) != NULL){
	len = strlen(line);
	int16_t i=0;
	int16_t j=strlen(line)-1;

	if(line[len-1] == '\n')
	{
	j--;
	}

	while(i<j){
	line[i]=line[i]+line[j];
	line[j]=line[i]-line[j];
	line[i]=line[i]-line[j];
	j--;
	i++;
	}

	if (len > 0) {
		printf("%s",line);
        }
}

}

