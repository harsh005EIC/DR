/*
* File Name     : 170904_harsh_DR_module1_T006_1-15.c
* Description   : use function to convert celsius to fahr
* Author        : harsh_kerai
* Created       : 10-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include "header.h"

void celsius_to_fahr(void)
{
double c;
printf("please enter valid celsius value:");

if(scanf("%lf",&c) != 1)
{
printf("enter valid input");
return;
}

double f=(c * 9.0/5.0) + 32;
printf("F=%lf\n",f);
}
