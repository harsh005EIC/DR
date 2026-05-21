/*
* File Name     : 170877_harsh_DR_module1_T006_1-4.c
* Description   : Write a program to print the corresponding Celsius to Fahrenheit table.
* Author        : harsh_kerai
* Created       : 05-02-2026
*/

#include <stdio.h>
#include "header.h"
#include <stdint.h>

void cels_to_fahr_user_input(void)
{
double c;
float f;
printf("Enter Celsius value : ");

if (scanf("%lf", &c) != 1) {
        printf("Invalid input! Please enter a number.\n");
        return;
}

f=( c * 9.0/5.0 )+32;

printf("\nF = %.2f",f);

}
