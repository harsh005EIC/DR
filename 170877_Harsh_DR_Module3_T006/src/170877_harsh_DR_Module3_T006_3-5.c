/*
* File Name     : 170904_harsh_DR_module2_T006_3-5.c
* Description   : Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s.
		  In particular, itob(n,s,16) formats s as a hexadecimal integer in s.
* Author        : harsh_kerai
* Created       : 26-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<limits.h>
#include"header.h"

void reverse(char s[])
{
	int8_t i, j;
	char temp;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
	}
}

void int_to_base(int n, char s[], int b)
{
int8_t i = 0;
int8_t sign;
unsigned int num;

	if (b < 2 || b > 36)
	{
	return;
	}

sign = n;

	if (n < 0)
	num = -(unsigned int)n;

	else
        num = n;

do{
	int8_t digit = num % b;

	if (digit < 10)
		s[i++]=digit + '0';

	else
            s[i++] = digit - 10 + 'a';

        num=num/b;
}while(num > 0);

	if (sign < 0)
	s[i++] = '-';

	s[i]= '\0';

reverse(s);
}

void itob(void)
{
char s[50];
int8_t number;
int8_t base;

	printf("Enter a number to conver it base:\n");
	scanf("%hhd",&number);

	printf("Enter a base number:\n");
	scanf("%hhd",&base);

	int_to_base(number, s, base);
	printf("255 in base 16 = %s\n", s);

}
