/*
* File Name     : 170904_harsh_DR_module4_T006_4-7.c
* Description   : Write a routine ungets(s) that will push back an entire string onto the input. Should ungets
		  know about buf and bufp, or should it just use ungetch?
* Author        : harsh_kerai
* Created       : 06-02-2026
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int8_t bufp = 0;

	int16_t getch(void)
	{
	if (bufp > 0)
	 return buf[--bufp];
	else
	 return getchar();
	}


	void ungetch(int c)
	{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
	}

	void ungets(char s[])
	{
	int i;
		for (i = strlen(s)-1; i >= 0; i--)
        	{
		   ungetch(s[i]);
		}
	}

	void push_back_entire_string(void)
	{
 	int16_t c;
	char s[1000];
	char string[1000];
	while((fgets(s,sizeof(s),stdin)) != NULL)
	strcat(string,s);
       	ungets(string);

	while ((c = getch()) != EOF)
	printf("%c",c);
	}

