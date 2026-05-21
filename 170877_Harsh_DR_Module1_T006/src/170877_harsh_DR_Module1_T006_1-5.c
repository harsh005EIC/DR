/*
* File Name     : 170877_harsh_DR_module1_T006_1-5.c
* Description   : Modify the temperature conversion program to print the table in reverse order,
		  that is, from 300 degrees to 0.
* Author        : harsh_kerai
* Created       : 05-02-2026
*/
#include <stdio.h>
#include "header.h"
#include <stdint.h>

void Celsius_to_Fahrenheit_table_300_to_0(void)
{
	int32_t c;
	float f;

	printf("Celsius to Fahrenheit\n");

	for (c = 300; c >= 0; c -= 10)
	{
		f = (c * 9.0/5.0) + 32;
		printf("%3d\t%6.1f\n",c,f);
	}
}
