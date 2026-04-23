/*
 * File Name     : 170877_harsh_DR_module5_T006_5-18.c
 * Description   : Make dcl recover from input errors
 * Author        : harsh_kerai
 * Date          : 08/04/2025
 */

#include "header.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100
        enum
        {
                NAME,
                PARENS,
                BRACKETS
        };

        int tokentype;
        char token[MAXTOKEN];
        char name[MAXTOKEN];
        char datatype[MAXTOKEN];
        char out[1000];

        int gettoken(void);
        void dcl(void);
        void dirdcl(void);

        int errorFlag = 0;

        void dcl(void)
        {
                int ns;

                for (ns = 0; gettoken() == '*';)
                        ns++;

                dirdcl();

                if (errorFlag)
                {
                        return;
                }

                while (ns-- > 0)
                        strcat(out, " pointer to");
        }

        void dirdcl(void)
        {
                int type;

                if (tokentype == '(')
                {
                        dcl();
                        if (tokentype != ')')
                        {
                                printf("Syntax error : missing closing )\n");
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
                        printf("Syntax error : expected name here\n");
                        errorFlag = 1;
                        return;
                }

                while (!errorFlag)
                {
                        type = gettoken();

                        if (type == PARENS)
                                strcat(out, " function returning");
                        else if (type == BRACKETS)
                        {
                                strcat(out, " array");
                                strcat(out, token);
                                strcat(out, " of");
                        }
                        else if (type == '(')
                        {
                                strcat(out, " function returning");

                                while ((type = gettoken()) != ')' && type != EOF && type != '\n')
                                        ;
                        }
                        else
                        {
                                break;
                        }
                }
        }

        int gettoken(void)
        {
                int c;
                char *p = token;

                while ((c = getchar()) == ' ' || c == '\t')
                        ;

                if (c == '/')
                {
                        int next = getchar();

                        if (next == '/')
                        {

                                while ((c = getchar()) != '\n' && c != EOF)
                                        ;

                                return tokentype = '\n';
                        }
                        else
                        {
                                ungetc(next, stdin);
                                return tokentype = '/';
                        }
                }

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
                        {
                                *p++ = c;
                        }
                        if (c == ']')
                        {
                                *p++ = c;
                        }
                        else
                        {
                                printf("Syntax error : missing ]\n");
                                errorFlag = 1;
                        }
                        *p = '\0';

                        return tokentype = BRACKETS;
                }

                else if (isalpha(c))
                {
                        *p++ = c;
                        while ((c = getchar()) != EOF && isalnum(c))
                        {
                                *p++ = c;
                        }

                        *p = '\0';

                        if (c != EOF)
                        {
                                ungetc(c, stdin);
                        }

                        return tokentype = NAME;
                }
                else
                {
                        return tokentype = c;
                }
        }

        void recover(void)
        {
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                        ;
        }

        void direct_dcl()
        {
                while (1)
                {
                        printf("Enter input : ");

                        if (gettoken() == EOF)
                                break;

                        errorFlag = 0;

                        out[0] = '\0';
                        name[0] = '\0';
                        datatype[0] = '\0';

                        if (tokentype != NAME)
                        {
                                printf("Invalid datatype\n");
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
                                printf("Invalid : syntax error\n");
                                recover();
                                continue;
                        }

                        printf("%s: %s %s\n", name, out, datatype);
                }
        }
