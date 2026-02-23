/*
* File Name     : 170904_harsh_DR_module1_T006_1-2.c
* Description   : Experiment to find out what happens when prints's argument string contains \c,
		  where c is some character not listed above.
* Author        : harsh_kerai
* Created       : 04-02-2026
*/
#include <stdio.h>
#include "header.h"

void print_c_helloworld(void)
{
	printf("hi\c harsh\n");
}
