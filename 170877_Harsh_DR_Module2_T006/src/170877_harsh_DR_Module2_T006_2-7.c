/*
* File Name     : 170904_harsh_DR_module2_T006_2-7.c
* Description   : Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted
		  (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
* Author        : harsh_kerai
* Created       : 19-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include"header.h"

void invert(void){
int16_t x,p,n;

printf("Enter value of x : \n");
scanf("%hd",&x);

printf("Enter value of p : \n");
scanf("%hd",&p);

printf("Enter value of n : \n");
scanf("%hd",&n);


if(x<0 || p<0 || n<0){
printf("Enter positive value \n");
return;
}

int16_t one_bits=(1U << n)-1;

one_bits = one_bits << (p-n+1);

x= x ^ one_bits;

printf("%d\n",x);
return;
}
