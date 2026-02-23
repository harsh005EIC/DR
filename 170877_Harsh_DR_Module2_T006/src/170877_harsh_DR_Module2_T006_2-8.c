/*
* File Name     : 170904_harsh_DR_module2_T006_2-8.c
* Description   : Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions.
* Author        : harsh_kerai
* Created       : 19-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include"header.h"

void rightrot(void){
uint32_t x;
int8_t n;

printf("Enter a value of x : \n");
scanf("%u",&x);

printf("Enter a value of n : \n");
scanf("%hhd",&n);

uint32_t right_most;
right_most = x & ( (1U<<n) - 1);
right_most = right_most << (31-n+1);
x = x >> n;
x = x | right_most;
printf("%u",x);
}
