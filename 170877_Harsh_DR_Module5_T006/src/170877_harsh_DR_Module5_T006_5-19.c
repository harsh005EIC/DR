/*
* File Name     : 170877_harsh_DR_module5_T006_5-19.c
* Description   : undcl program is used to convert a word description of a declaration into a C declaration.
                  ensure that the program does not add unnecessary parentheses around parts of the declaration.
* Author        : harsh_kerai
* Date          : 13/04/2025
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define MAXTOKEN 100
#define MAXOUT 2000

enum { NAME, PARENS, BRACKETS };

int16_t tokentype;
char token[MAXTOKEN];
char out[MAXOUT];
char temp[MAXOUT];

/*
* File Name     : 170877_harsh_DR_module5_T006_5-19.c
* Description   : gettoken: return next token
* Author        : harsh_kerai
* Date          : 13/04/2025
*/

	int16_t gettoken(void){
		int16_t c, getch(void);
		void ungetch(int);
		char *p = token;

		while((c = getch()) == ' ' || c == '\t');

		if(c == '('){
			if((c = getch()) == ')')
			{
				strcpy(token, "()");
				return tokentype = PARENS;
			}

			else{
				ungetch(c);
				return tokentype = '(';
			}
		}

		else if (c == '[')
		{
			for(*p++ = c; (*p++ = getch()) != ']'; );
			*p = '\0';
			return tokentype = BRACKETS;
		}

		else if(isalpha(c))
		{
			for(*p++ = c; isalnum(c = getch()); )
			*p++ = c;
			*p = '\0';
			ungetch(c);
			return tokentype = NAME;
		}

		else{
			token[0] = c;
			token[1] = '\0';
			return tokentype = c;
		}
	}
/*
* File Name     : 170877_harsh_DR_module5_T006_5-19.c
* Description   : getch function take character from stdin / ungetch function used for store character into buffer.
* Author        : harsh_kerai
* Date          : 13/04/2025
*/

	#define BUFSIZE 100
	char buf[BUFSIZE];
	int16_t bufp = 0;

	int16_t getch(void)
	{
		return (bufp > 0) ? buf[--bufp] : getchar();
	}

	void ungetch(int c)
	{
		if(bufp < BUFSIZE)
		buf[bufp++] = c;
	}

/*
* File Name     : 170877_harsh_DR_module5_T006_5-19.c
* Description   : undcl program is used to convert a word description of a declaration into a C declaration.
                  ensure that the program does not add unnecessary parentheses around parts of the declaration.
* Author        : harsh_kerai
* Date          : 13/04/2025
*/
	void undeclare()
	{
		int16_t type;

		while(gettoken() != EOF)
		{
			strcpy(out, token);

				while((type = gettoken()) != '\n')
				{
					if(type == PARENS || type == BRACKETS)
					{
						if(out[0] == '*')
						{
 							if(snprintf(temp, sizeof(temp), "(%s)%s", out, token) >= (int)sizeof(temp))
							printf("Error: too long\n");
						}
						else
						{
							if(snprintf(temp, sizeof(temp), "%s%s", out, token) >= (int)sizeof(temp))
							printf("Error: too long\n");
						}
						strcpy(out, temp);
 					}
					else if(type == '*')
					{
						if(snprintf(temp, sizeof(temp), "*%s", out) >= (int)sizeof(temp))
						printf("Error: too long\n");

						strcpy(out, temp);
					}

					else if(type == NAME)
					{
						if(snprintf(temp, sizeof(temp), "%s %s", token, out) >= (int)sizeof(temp))
						printf("Error: too long\n");

						strcpy(out, temp);
					}
				}

				printf("%s\n", out);
		}
	}
