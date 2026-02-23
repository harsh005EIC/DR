/*
* File Name     : 170904_harsh_DR_module2_T006_2-10.c
* Description   : Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression
		  instead of if-else.
* Author        : harsh_kerai
* Created       : 19-02-2026
*/


#include<stdio.h>
#include<stdint.h>
#include"header.h"

void upper_to_lower(void){
int32_t c;

	while((c=getchar()) != EOF){
	c=(c >= 'A' && c <= 'Z')?(c+32):c;
	putchar(c);
	}
}
