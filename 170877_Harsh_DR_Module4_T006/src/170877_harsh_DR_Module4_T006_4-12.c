/*
* File Name     : 170904_harsh_DR_module4_T006_4-12.c
* Description   : Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by
		  calling a recursive routine.
* Author        : harsh_kerai
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void itoa_recursive(int n, char s[], int *i)
{
    if (n / 10)
        itoa_recursive(n / 10, s, i);

    s[(*i)++] = n % 10 + '0';
}

void ftoa_recursive(double num, char s[])
{
	int i = 0;

	if(num < 0){
	  s[i++] = '-';
          num = -num;
	}

	int integer = (int)num;
	double fraction = num - (double)integer;

	if(integer == 0)
	  s[i++] = '0';
	else
	  itoa_recursive(integer, s, &i);

	    if (fraction > 0) {
		s[i++] = '.';
	    for (int j = 0; j < 3; j++) {
		fraction *= 10;
                int digit = (int)fraction;
                s[i++] = digit + '0';
                fraction -= digit;
	    }
	    }

    s[i] = '\0';
}

void itoa_recursion(void)
{
char s[100];
double num;

	printf("Enter number: ");
	scanf("%lf", &num);

	ftoa_recursive(num, s);

	printf("String = %s\n", s);
}
