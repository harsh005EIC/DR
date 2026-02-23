/*
* File Name     : 170904_harsh_DR_module1_T006_1-6.c
* Description   : Verify that the expression getchar() != EOF is 0 or 1.
* Author        : harsh_kerai
* Created       : 06-02-2026
*/

#include <stdio.h>
#include "header.h"
#include <stdint.h>

void expression_of_EOF(void)
{
int8_t result;

result=(getchar() != EOF);
printf("%d\n",result);

}
