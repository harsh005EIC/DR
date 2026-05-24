/*
* File Name     : 170877_harsh_DR_module2_T006_3-4.c
* Description   : In a two's complement number representation, our version of itoa does not handle the largest negative number,
		  that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value correctly,
		  regardless of the machine on which it runs.
* Author        : harsh_kerai
* Created       : 25-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include"header.h"

void reverse(char s[]){
	int8_t i, j;
	char temp;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
	}
}

void integer_to_string(int number,char s[])
{
	int8_t index=0;
	int32_t original_number=number;

	if(original_number>0){
	number = -number;
	}

	do
	{
	s[index++]=-(number%10)+'0';
	number=number/10;
	}while(number<0);

	if(original_number<0){
	s[index++]='-';
	}
	s[index]='\0';
	reverse(s);
}

void itoa(void)
{
	int32_t number;
	char s[1000];
	int64_t temp;

	printf("Enter a number to convert into integer to string : ");
        scanf("%ld", &temp);

	if (temp < INT32_MIN || temp > INT32_MAX)
	{
	printf("Not a valid number\n");
	return;
	}

	number=(int32_t)temp;
	integer_to_string(number,s);
	printf("%s\n",s);
}
