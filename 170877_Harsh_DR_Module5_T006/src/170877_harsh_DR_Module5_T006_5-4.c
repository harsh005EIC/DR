/*
* File Name     : 170877_harsh_DR_module5_T006_5-4.c
* Description   : Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s,
		  and zero otherwise.
* Author        : harsh_kerai
* Date          : 30/03/2025
*/
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include"header.h"

int8_t rightmost_occur(char s[],char char_str[],int16_t length_str,int16_t length_char_str)
{
	if(length_str < length_char_str)
	return 0;

	int8_t sub_idx=length_char_str;
			while(sub_idx != 0)
			{
				if(char_str[sub_idx] != s[length_str])
				{
				 return 0;
				 break;

				}
			sub_idx--;
			length_str--;
			}

	return 1;


}

void substringatend(void)
{
char string[1000]="";
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

	printf(" output: %d.\n", rightmost_occur(string,char_str,--length_str,--length_char_str));

}
