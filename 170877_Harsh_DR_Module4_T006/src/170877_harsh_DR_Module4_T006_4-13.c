/*
* File Name     : 170904_harsh_DR_module4_T006_4-13.c
* Description   : Write a recursive version of the function reverse(s), which reverses the string s in place.
* Author        : harsh_kerai
*/
#include <stdio.h>
#include <string.h>
#include "header.h"

void reverse_recursive(char s[], int left, int right)
{
    if (left >= right)
        return;

    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    reverse_recursive(s, left + 1, right - 1);
}
void reverse_string_recursion(void){
char s[100];

	printf("Enter string: ");
	fgets(s, sizeof(s), stdin);
	reverse_recursive(s, 0, strlen(s) - 1);

	printf("Reversed string = %s\n", s);
}

