/*
* File Name     : 170877_harsh_DR_module1_T006_1-3.c
* Description   : Modify the temperature conversion program to print a heading above the table.
* Author        : harsh_kerai
* Created       : 04-02-2026
*/

#include <stdio.h>
#include "header.h"
#include <stdint.h>

void fahr_to_cels_table_0to300(void)
{
	int32_t f;
	printf("FAHRENHEIT TO CELSIUS TABLE\n");
	printf("Fahrenheit\tCelsius\n");

	for (f = 0; f <= 300; f += 20)
	{
		printf("%3d\t%6.1f\n", f, (5.0/9.0) * (f - 32));
	}
}
