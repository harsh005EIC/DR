/*
* File Name     : 170904_harsh_DR_module2_T006_2-5.c
* Description   : Write the function any(s1,s2), which returns the first location in a string s1 where any character from the
 		  string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the 
		  same job but returns a pointer to the location.) 
* Author        : harsh_kerai
* Created       : 18-02-2026
*/


#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include"header.h"

void any(void){

char str1[1000]="";
char str2[1000]="";
unsigned char c;
printf("Enter a string 1:\n");
fgets(str1,sizeof(str1),stdin);
printf("Enter a string 2:\n");
fgets(str2,sizeof(str2),stdin);

int16_t str2_arr[256]={0};

int16_t length_str1 = strlen(str1);
int16_t length_str2 = strlen(str2);

	if(str1[length_str1-1] == '\n')
	   str1[--length_str1]='\0';
	if(str2[length_str2-1] == '\n')
           str2[--length_str2]='\0';

	for(int16_t i=0;str2[i]!='\0';i++)
	{
	 c=str2[i];
	 str2_arr[c]=1;
	}

	for(int16_t i=0;str1[i] != '\0';i++)
	{
	c=str1[i];
	if(str1[i]&&str2_arr[c]){
	printf("Duplicate character is found at position %d in string 1",i);
	break;
	}
	}

}
