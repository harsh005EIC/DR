/*
* File Name     : 170904_harsh_DR_module1_T006_1-11.c
* Description   : How would you test the word count program?
		  What kinds of input are most likely to uncover bugs if there are any?
* Author        : harsh_kerai
* Created       : 09-02-2026
*/

#include<stdio.h>
#include "header.h"
#include<stdint.h>
void word_count(void)
{

int16_t c;
int32_t wc=0;
int8_t state=0;

	while( (c=getchar()) != EOF )
	{
	if( c == ' ' || c == '\t' || c=='\n' )
	 {
		state=0;
		continue;
	 }

	else
	 {

		if(!state)
		{
		 ++wc;
		 state=1;
		}
	 }
	}
printf("total word count is %d \n",wc);
}

