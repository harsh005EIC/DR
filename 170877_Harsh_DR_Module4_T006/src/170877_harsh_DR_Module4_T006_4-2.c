/*
* File Name     : 170904_harsh_DR_module4_T006_4-2.c
* Description   : Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be
		  followed by e or E and an optionally signed exponent.
* Author        : harsh_kerai
* Created       : 27-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include"header.h"

int16_t sign_exponent(char s[],int8_t index){

double tenpower=0;
index=index+1;

	if(s[index] == '-' || s[index] == '+')
	{
	 index=index+1;
	}

	 while(s[index] != '\0')
	 {
	  tenpower=(tenpower*10) + s[index] - '0';
	  index++;
	 }

return tenpower;
}

void scientific_notation(char s[],double number)
{
int8_t index=0;
int16_t ten_power=0;
int8_t divison=0;
int8_t multiply=0;
int8_t decimal_point = 0;
double decimal_division = 1;

	while(s[index] != '\0')
	{


	if(s[index] == '.')
	{
	decimal_point = 1;
	index = index + 1;
	}

	if(s[index] == '-')
	{
	decimal_division = -decimal_division;
	index = index + 1;
	}

	if(s[index] == 'e'){

		if(s[index+1] == '-')
		{
		divison = 1;
		}
		else{
		multiply = 1;
		}

	ten_power = sign_exponent(s,index);
	break;
	}

	 if(decimal_point == 1)
          {
           decimal_division = decimal_division / 10;
          }

	 number=(number * 10) + s[index] - '0';
	 index++;
	}

	if(divison == 1)
	{
	 while(ten_power !=0)
	 {
	  number = number / 10;
	  ten_power--;
	 }
	}

	if(multiply == 1)
	{
	 while(ten_power != 0)
	 {
	  number = number * 10;
	  ten_power--;
	 }
	}
printf("number is %lf : \n",number*decimal_division);
}
void atofloat(void)
{
char s[1000]="";
double number=0;
int8_t str_len=0;

printf("Enter a string with scientific naotation : ");
fgets(s,sizeof(s),stdin);
str_len = strlen(s);

if(s[str_len-1] == '\n')
s[--str_len]='\0';

scientific_notation(s,number);

}
