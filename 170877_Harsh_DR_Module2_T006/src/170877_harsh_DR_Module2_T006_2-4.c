/*
* File Name     : 170904_harsh_DR_module2_T006_2-4.c
* Description   : Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in
		  the string s2.
* Author        : harsh_kerai
* Created       : 17-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include"header.h"
#include<ctype.h>
void squeeze(void)
{
char str1[1000]="";
char str2[1000]="";
unsigned char c;
printf("Enter string 1 : \n");
fgets(str1, sizeof(str1), stdin);
printf("Enter string 2 :\n");
fgets(str2, sizeof(str2), stdin);

int16_t str1_arr[256]={0};

for(int16_t i=0;str1[i] != '\0' ;i++){
	c=str1[i];
	str1_arr[tolower(c)]=1;
}
for(int16_t i=0;str2[i] != '\0';i++){
	c=str2[i];
	str1_arr[tolower(c)]=0;
}

for(int16_t i=0;str1[i] != '\0';i++){
c=str1[i];
if(str1[i] && str1_arr[tolower(c)])
	{
	  printf("%c",str1[i]);
	}
else
{
	continue;
}
}
}
