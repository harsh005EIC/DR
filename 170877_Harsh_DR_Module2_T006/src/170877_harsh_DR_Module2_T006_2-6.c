/*
* File Name     : 170904_harsh_DR_module2_T006_2-6.c
* Description   : Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set
		  to the rightmost n bits of y, leaving the other bits unchanged
* Author        : harsh_kerai
* Created       : 18-02-2026
*/


#include<stdio.h>
#include<stdint.h>
#include"header.h"

void setbits(void){
int16_t x,p,n,y;

printf("Enter value of x : \n");
scanf("%hd",&x);

printf("Enter value of p : \n");
scanf("%hd",&p);

printf("Enter value of n : \n");
scanf("%hd",&n);

printf("Enter value of y : \n");
scanf("%hd",&y);

if(x<0 || p<0 || n<0 || y<0){
printf("Enter positive value \n");
return;
}

int16_t one_bits= (1U << n) - 1;
int16_t y_bits;

y = y & one_bits;
y_bits = y << (p-n+1);

one_bits = ~(one_bits << (p-n+1));

x=x & one_bits;

x = x | y_bits;


printf("%d \n",x);
}
