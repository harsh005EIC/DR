/*
* File Name     : 170877_harsh_DR_module5_T006_5-3.c
* Description   : Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t) copies the
		  string t to the end of s.
* Author        : harsh_kerai
* Date          : 30/03/2025
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

void strcat_ptr(char *s, const char *t)
{
	while (*s != '\0')
	  s++;

	while((*s++ = *t++) != '\0');
}

void stringcat(void){

	char s[50];
	char t[50];

	printf("Enter first string: ");
	fgets(s, sizeof(s), stdin);

	printf("Enter second string: ");
	fgets(t, sizeof(t), stdin);

	s[strcspn(s, "\n")] = '\0';
	t[strcspn(t, "\n")] = '\0';

	printf("\nBefore:\n");
	printf("s: %s\n", s);
	printf("t: %s\n", t);

	strcat_ptr(s, t);

	printf("\nAfter:\n");
	printf("s: %s\n", s);
}
