/*
* File Name     : 170904_harsh_DR_module1_T006_1-14.c
* Description   : Write a program to print a histogram of the frequencies of different characters in its input.
* Author        : harsh_kerai
* Created       : 10-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include"header.h"

void print_histogram_lengths_words(void){
int16_t c;
int16_t character[256]={0};

	while((c=getchar()) != EOF)
	 {
		if (c >= 0 && c < 256)
		{
		character[c]++;
		}
	 }
for(int16_t i=0;i<256;i++){
	if(character[i] !=0)
		{
		 if (i==' '){
		 printf("SP :");

		 for(int32_t j=0;j<character[i];j++)
		 {
			printf("*");
		 }
		  printf("\n");
		 }

		 else if (i=='\n'){
			printf("\\n :");
			for(int32_t j=0;j<character[i];j++)
                          {
                           printf("*");
                          }
			    printf("\n");
		 }

		 else if (i=='\t'){
			printf("\\t :");
			for(int32_t j=0;j<character[i];j++)
                          	{
                           	printf("*");
                          	}
				printf("\n");
		 }

		else{
			printf("%c :",i);
			for(int32_t j=0;j<character[i];j++)
                          {
                           printf("*");
                          }

			printf("\n");
			}
		}
	}

}

