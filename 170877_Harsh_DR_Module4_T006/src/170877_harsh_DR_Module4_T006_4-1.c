/*
* File Name     : 170904_harsh_DR_module4_T006_4-1.c
* Description   : Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if
		  there is none.
* Author        : harsh_kerai
* Created       : 27-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include"header.h"

void rightmost_occur(char s[],char char_str[],int16_t *char_index)
{

	for(int8_t index = 0;s[index] != '\0'; index++)
	{
	int8_t state=1;
		if(char_str[0] == s[index])
		{
			int8_t sub_idx=0;
			while(char_str[sub_idx] != '\0')
			{
				if(char_str[sub_idx] != s[index+sub_idx])
				{
				 state=0;
				 break;
				}
			sub_idx++;
			}

			if(state == 1)
			{
			*char_index=index;
			}
		}

	}

}

void strindex(void)
{
char string[1000]="";
int16_t char_index= -1;
char char_str[1000]="";
int16_t length_str;
int16_t length_char_str;

	printf("Enter a string:");
	fgets(string,sizeof(string),stdin);
	length_str=strlen(string);

		if(string[length_str-1] == '\n')
		string[--length_str]='\0';

	printf("Enter a character string:");
	fgets(char_str,sizeof(char_str),stdin);
	length_char_str=strlen(char_str);

		if(char_str[length_char_str-1] == '\n')
		char_str[--length_char_str]='\0';

	rightmost_occur(string,char_str,&char_index);
	printf("%s output: %d.\n",char_str,char_index);

}
