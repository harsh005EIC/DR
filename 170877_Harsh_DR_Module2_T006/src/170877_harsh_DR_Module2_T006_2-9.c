/*
* File Name     : 170904_harsh_DR_module2_T006_2-9.c
* Description   : count set bits in number
* Author        : harsh_kerai
* Created       : 19-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include"header.h"

void setbits(void){
int16_t n;

printf("Enter a number : \n");
scanf("%hd",&n);

int8_t count;
	while(n>0)
	{
	 n=n&(n-1);
	 count++;
	}
printf("setbits in number is %d \n",count);
}
