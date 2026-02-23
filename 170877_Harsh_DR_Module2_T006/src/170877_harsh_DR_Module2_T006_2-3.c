/*
* File Name     : 170904_harsh_DR_module2_T006_2-3.c
* Description   : Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X)
		  into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
* Author        : harsh_kerai
* Created       : 17-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include"header.h"

void htoi(void){
char hex[1000];
int16_t i=0;
int16_t integer=0;
int16_t value=0;

	printf("Enter a hexadecimal number: ");
	scanf("%s", hex);

	if(hex[0]=='0' && hex[1]=='X')
	i=2;

	while(hex[i] != '\0')
	{

		if(hex[i]>='0' && hex[i]<='9')
		{
		  value=hex[i]-'0';
		}
		else if(hex[i]>='A' && hex[i]<='F')
		{
		  value=hex[i]-'A'+10;
		}
		else if(hex[i]>='a' && hex[i]<='f')
		  value=hex[i]-'a'+10;
		else {
		printf("Invalid Hexadecimal Number!\n");
		return;
		}
		integer=integer*16 + value;
		i++;
	}

	printf("Integer equivalent = %d\n", integer);

}
