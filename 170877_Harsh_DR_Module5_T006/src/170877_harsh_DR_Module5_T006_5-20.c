/*
* File Name     : 170877_harsh_DR_module5_T006_5-20.c
* Description   : dcl program is used to convert a C declaration into a word description.Handle function argument types.
                  Recognize and process qualifiers like const
* Author        : harsh_kerai
* Date          : 13/04/2025
*/

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100
#define MAXOUT 1000

	enum
	{
        	NAME,
        	PARENS,
        	BRACKETS
	};

int16_t tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[MAXOUT];

int8_t errorFlag = 0;

int16_t gettoken(void);
void dcl(void);
void dirdcl(void);
void recover(void);

        void dcl_argument(void)
        {
                while (1)
                {
                        printf("Enter declaration (CTRL+D to exit): ");

                        do
                        {
                                if (gettoken() == EOF)
                                        return;
                        } while (tokentype == '\n');

                        errorFlag = 0;
                        out[0] = '\0';
                        name[0] = '\0';
                        datatype[0] = '\0';

                        if (tokentype != NAME)
                        {
                                printf("Error: invalid datatype\n");
                                recover();
                                continue;
                        }

                        strcpy(datatype, token);

                        dcl();

                        if (errorFlag)
                        {
                                if (tokentype != '\n')
                                        recover();
                                continue;
                        }

                        if (tokentype != '\n' && tokentype != EOF)
                        {
                                printf("Error: syntax error\n");
                                recover();
                                continue;
                        }

                        printf("%s: %s %s\n", name, out, datatype);
                }
        }

        void dcl(void)
        {
                int8_t ns = 0;

                while (gettoken() == '*')
                        ns++;

                dirdcl();

                if (errorFlag)
                        return;

                while (ns-- > 0)
                        strcat(out, " pointer to");
        }

        void dirdcl(void)
        {
                int16_t type;

                if (tokentype == '(')
                {
                        dcl();
                        if (tokentype != ')')
                        {
                                printf("Error: missing )\n");
                                errorFlag = 1;
                                return;
                        }
                }
                else if (tokentype == NAME)
                {
                        strcpy(name, token);
                }
                else
                {
                        printf("Error: expected name\n");
                        errorFlag = 1;
                        return;
                }

                while (!errorFlag)
                {
                        type = gettoken();

                        if (type == PARENS)
                        {
                                strcat(out, " function returning");
                        }
                        else if (type == BRACKETS)
                        {
                                strcat(out, " array");
                                strcat(out, token);
                                strcat(out, " of");
                        }
                        else if (type == '(')
                        {
                                char args[MAXOUT] = "";
                                int first = 1;

                                strcat(args, "(");

                                while ((type = gettoken()) != ')' && type != EOF && type != '\n')
                                {
                                        if (type == NAME)
                                        {
                                                if (!first)
                                                        strcat(args, ", ");
                                                strcat(args, token);
                                                first = 0;
                                        }
                                        else if (type == '*')
                                        {
                                                strcat(args, "*");
                                        }
                                        else if (type == PARENS)
                                        {
                                                strcat(args, " function returning");
                                        }
                                        else if (type == BRACKETS)
                                        {
                                                strcat(args, " array");
                                                strcat(args, token);
                                                strcat(args, " of");
                                        }
                                }

                                if (type != ')')
                                {
                                        printf("Error: missing ) in arguments\n");
                                        errorFlag = 1;
                                        return;
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

        int16_t gettoken(void)
        {
                int16_t c;
                char *p = token;

                while ((c = getchar()) == ' ' || c == '\t');

                if (c == '\n' || c == EOF)
                        return tokentype = c;

                if (c == '(')
                {
                        if ((c = getchar()) == ')')
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
                else if (c == '[')
                {
                        *p++ = c;

                        while ((c = getchar()) != ']' && c != EOF && c != '\n')
                                *p++ = c;

                        if (c == ']')
                        {
                                *p++ = c;
                                *p = '\0';
                                return tokentype = BRACKETS;
                        }
                        else
                        {
                                printf("Error: missing ]\n");
                                errorFlag = 1;
                                return tokentype = '\n';
                        }
                }
                else if (isalpha(c))
                {
                        *p++ = c;

                        while (isalnum(c = getchar()))
                                *p++ = c;

                        *p = '\0';

                        if (c != EOF)
                                ungetc(c, stdin);

                        return tokentype = NAME;
                }
                else
                {
                        return tokentype = c;
                }
        }

        /* recover */
        void recover(void)
        {
                int16_t c;
                while ((c = getchar()) != '\n' && c != EOF)
                        ;
        }
