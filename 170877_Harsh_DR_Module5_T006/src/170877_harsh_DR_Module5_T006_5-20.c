/*
* File Name     : 170877_harsh_DR_module5_T006_5-20.c
* Description   : dcl program is used to convert a C declaration into a word description.Handle function argument types.
		  Recognize and process qualifiers like const
* Author        : harsh_kerai
* Date          : 13/04/2025
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define MAXOUT 1000

enum { NAME, PARENS, BRACKETS };

	int tokentype;
	char token[MAXTOKEN];
	char name[MAXTOKEN];
	char datatype[MAXTOKEN];
	char out[MAXOUT];

	int errorFlag = 0;

/* function prototypes */
	int gettoken(void);
	void dcl(void);
	void dirdcl(void);
	void recover(void);

/* dcl: parse a declarator */
	void dcl(void)
	{
		int ns = 0;

		while(gettoken() == '*')
			ns++;
		dirdcl();

		if(errorFlag)
			return;

		while(ns-- > 0)
			strcat(out, " pointer to");
	}

/* dirdcl: parse a direct declarator */
	void dirdcl(void)
	{
		int type;

		if(tokentype == '(')
		{
			dcl();
			if(tokentype != ')')
			{
				printf("Syntax error: missing )\n");
				errorFlag = 1;
				return;
			}
		}

		else if(tokentype == NAME)
		{
			strcpy(name, token);
		}

		else{
			printf("Syntax error: expected name\n");
			errorFlag = 1;
			return;
		}

		while(!errorFlag)
		{
			type = gettoken();

			if(type == PARENS)
			{
				strcat(out, " function returning");
			}
			else if(type == BRACKETS)
			{
				strcat(out, " array");
				strcat(out, token);
				strcat(out, " of");
			}
			else if(type == '(')
			{
				char args[MAXOUT] = "";
				int first = 1;

				strcat(args, "(");

				while((type = gettoken()) != ')' && type != EOF && type != '\n')
				{
					if(type == NAME)
					{
						if(!first)
							strcat(args, ", ");

						strcat(args, token);
						first = 0;
					}

					else if(type == '*')
					{
						strcat(args, " pointer to");
					}
					else if(type == PARENS)
					{
						strcat(args, " function returning");
					}
					else if(type == BRACKETS)
					{
						strcat(args, " array");
						strcat(args, token);
						strcat(args, " of");
					}
				}

				strcat(args, ")");

				strcat(out, " function ");
				strcat(out, args);
				strcat(out, " returning");
			}
			else
			{
				break;
			}
		}
	}

/* gettoken: return next token */
	int gettoken(void)
	{
		int c;
		char *p = token;

		while((c = getchar()) == ' ' || c == '\t');

		if(c == '/')
		{
			int next = getchar();
			if(next == '/')
			{
				while((c = getchar()) != '\n' && c != EOF);
				return tokentype = '\n';
			}
			else
			{
				ungetc(next, stdin);
				return tokentype = '/';
			}
		}

		if(c == '(')
		{
			if((c = getchar()) == ')')
			{
				strcpy(token, "()");
				return tokentype = PARENS;
			}
			else
			{
				ungetc(c, stdin);
				return tokentype = '(';
			}
		}

		else if(c == '[')
		{
			*p++ = c;
			while((c = getchar()) != ']' && c != EOF && c != '\n')
			*p++ = c;

			if(c == ']')
				*p++ = c;
			else
			{
				printf("Syntax error: missing ]\n");
				errorFlag = 1;
			}

			*p = '\0';
			return tokentype = BRACKETS;
		}

		else if(isalpha(c))
		{
			*p++ = c;
			while((c = getchar()) != EOF && isalnum(c))
				*p++ = c;

			*p = '\0';

			if(c != EOF)
				ungetc(c, stdin);

			return tokentype = NAME;
		}

		else{
			return tokentype = c;
		}
	}

/* recover from error */
	void recover(void)
	{
		int c;
		while((c = getchar()) != '\n' && c != EOF);
	}

	void dcl_argument(void)
	{
		while(1)
		{
			printf("Enter declaration: ");

			if(gettoken() == EOF)
			break;

			errorFlag = 0;
			out[0] = '\0';
			name[0] = '\0';
			datatype[0] = '\0';

			if(tokentype != NAME)
			{
				printf("Invalid datatype\n");
				recover();
				continue;
			}

			strcpy(datatype, token);

			while(gettoken() == NAME)
			{
				strcat(datatype, " ");
				strcat(datatype, token);
			}

			dcl();

			if(errorFlag)
			{
				recover();
				continue;
			}

			if(tokentype != '\n' && tokentype != EOF)
			{
				printf("Syntax error\n");
				recover();
				continue;
			}

			printf("%s: %s %s\n", name, out, datatype);
		}

		return;
	}
