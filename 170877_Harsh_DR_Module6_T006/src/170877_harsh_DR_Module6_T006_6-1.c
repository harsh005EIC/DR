/*
* File Name     : 170877_harsh_DR_module6_T006_6-1.c
* Description   : Our version of getword does not properly handle underscores, string constants, comments, or preprocessor control
		  lines. Write a better version.
* Author        : harsh_kerai
* Date          : 13/04/2025
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 100

	struct key{
		char *word;
		int count;
	};

	struct key keytab[]={
		{"auto", 0}, {"break", 0}, {"case", 0}, {"char", 0},
		{"const", 0}, {"continue", 0}, {"default", 0}, {"do", 0},
		{"double", 0}, {"else", 0}, {"enum", 0}, {"extern", 0},
 		{"float", 0}, {"for", 0}, {"goto", 0}, {"if", 0},
		{"int", 0}, {"long", 0}, {"register", 0}, {"return", 0},
		{"short", 0}, {"signed", 0}, {"sizeof", 0}, {"static", 0},
		{"struct", 0}, {"switch", 0}, {"typedef", 0}, {"union", 0},
		{"unsigned", 0}, {"void", 0}, {"volatile", 0}, {"while", 0}
	};

	#define NKEYS (sizeof keytab / sizeof keytab[0])

	int getword(char *, int);
	int binsearch(char *, struct key *, int);
	int getch(void);
	void ungetch(int);

	void get_word(void)
	{
		int n;
		char word[MAXWORD];

		while(getword(word, MAXWORD) != EOF)
		{
 			if(isalpha(word[0]) || word[0] == '_')
			{
				n = binsearch(word, keytab, NKEYS);
				if(n >= 0)
					keytab[n].count++;
			}
 		}

		for(n = 0; n < NKEYS ; n++)
			if(keytab[n].count > 0)

		printf("%4d %s\n", keytab[n].count, keytab[n].word);

	return;
	}

	int binsearch(char *word, struct key tab[], int n)
	{
		int low = 0, high = n - 1, mid, cond;

		while(low <= high)
		{
			mid = (low + high) / 2;

			if((cond = strcmp(word, tab[mid].word)) < 0)
				high = mid - 1;
			else if (cond > 0)
				low = mid + 1;
			else
				return mid;
		}
		return -1;
	}

	int getword(char *word, int lim)
	{
		int c;
		char *w = word;

		while(isspace(c = getch()));

		if(c == EOF)
			return EOF;

		if(c == '#')
		{
			while((c = getch()) != '\n' && c != EOF);
			return getword(word, lim);
		}

		if(c == '/')
		{
			int d = getch();
			if(d == '/')
			{
				while((c = getch()) != '\n' && c != EOF);
				return getword(word, lim);
			}
			else if (d == '*')
			{
 				int prev = 0;
				while((c = getch()) != EOF)
				{
					if(prev == '*' && c == '/')
					break;
					prev = c;
				}
				return getword(word, lim);
			}
			else
			{
				ungetch(d);
			}
		}

		if(c == '"')
		{
			while ((c = getch()) != '"' && c != EOF)
				if(c == '\\')
				getch();
			return getword(word, lim);
		}

		if(c == '\'')
		{
			while ((c = getch()) != '\'' && c != EOF)
				if(c == '\\')
				getch();
			return getword(word, lim);
		}

		if(!isalpha(c) && c != '_')
		{
			*w++ = c;
			*w = '\0';
			return c;
		}

		*w++ = c;
		for(; --lim > 0; w++)
		{
			c = getch();
			if(!isalnum(c) && c != '_')
			{
				ungetch(c);
				break;
			}
			*w = c;
		}
 			*w = '\0';

			return word[0];
	}

	char buf[BUFSIZE];
	int bufp = 0;

	int getch(void)
	{
		return (bufp > 0) ? buf[--bufp] : getchar();
	}

	void ungetch(int c)
	{
		if(bufp >= BUFSIZE)
			printf("ungetch: too many characters\n");
		else
			buf[bufp++] = c;
	}
