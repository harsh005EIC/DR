/*
* File Name     : 170904_harsh_DR_module4_T006_4-14.c
* Description   : Define a macro swap(t,x,y) that interchanges two arguments of type t.
* Author        : harsh_kerai
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define swap(t,x,y) { t temp; temp = x; x = y; y = temp; }

int8_t isNumber(char s[])
{
	for(int8_t i = 0; s[i]; i++)

	if(isdigit(s[i]) || s[i] == '.' || s[i] == '-')
	return 1;

	return 0;
}

void macro_swap(void){
char a[100], b[100];

	printf("Enter first value: ");
	fgets(a, sizeof(a), stdin);

	printf("Enter second value: ");
	fgets(b, sizeof(b), stdin);


	a[strcspn(a,"\n")] = '\0';
	b[strcspn(b,"\n")] = '\0';

	if(isNumber(a) && isNumber(b)){
        double x = atof(a);
        double y = atof(b);

        printf("Before swap: %.2f %.2f\n", x, y);

        swap(double, x, y);

        printf("After swap: %.2f %.2f\n", x, y);
	}

	else{
        char x = a[0];
        char y = b[0];

        printf("Before swap: %c %c\n", x, y);

        swap(char, x, y);

        printf("After swap: %c %c\n", x, y);
    }
}
