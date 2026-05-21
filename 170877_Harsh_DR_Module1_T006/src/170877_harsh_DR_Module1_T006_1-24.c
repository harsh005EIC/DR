/*
* File Name     : 170877_harsh_DR_module1_T006_1-24.c
* Description   : Write a program to check a C program for rudimentary syntax errors like unmatched parentheses,
		  brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments.
		  (This program is hard if you do it in full generality.)
* Author        : harsh_kerai
* Created       : 13-02-2026
*/

#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <stdint.h>

#define MAXSTACK 1000

static char stack[MAXSTACK];
static int top = -1;

void push(char c)
{
	if (top < MAXSTACK - 1)
		stack[++top] = c;
}

char pop(void)
{
	if (top >= 0)
	return stack[top--];
	return '\0';
}

void rudimentary_syntax_errors(void)
{
    FILE *fp = fopen("/home/harsh005/input.c", "r");

    int c, line = 1;

	int8_t NORMAL=0;
	int8_t IN_STRING=1;
	int8_t IN_CHAR=2;
	int8_t IN_LINE_COMMENT=3;
	int8_t IN_BLOCK_COMMENT=4;
	int8_t state = NORMAL;

	while ((c = fgetc(fp)) != EOF)
	{
        if (c == '\n')
            line++;

        switch (state)
        {
        case 0:
            if (c == '"')
                state = IN_STRING;

            else if (c == '\'')
                state = IN_CHAR;

            else if (c == '/')
            {
                int next = fgetc(fp);

                if (next == '/')
                    state = IN_LINE_COMMENT;

                else if (next == '*')
                    state = IN_BLOCK_COMMENT;

                else
                    ungetc(next, fp);
            }

            else if (c == '(' || c == '{' || c == '[')
                push(c);

            else if (c == ')' || c == '}' || c == ']')
            {
                char open = pop();

                if ((c == ')' && open != '(') ||
                    (c == '}' && open != '{') ||
                    (c == ']' && open != '['))
                {
                    printf("Unmatched %c at line %d\n", c, line);
                }
            }
            break;

        case 1:
		if (c == '"')
                state = NORMAL;
            break;

        case 2:
		 if (c == '\'')
                state = NORMAL;
            break;

        case 3:
            if (c == '\n')
                state = NORMAL;
            break;

        case 4:
            if (c == '*')
            {
                int next = fgetc(fp);
                if (next == '/')
                    state = NORMAL;
                else
                    ungetc(next, fp);
            }
            break;
        }
    }

    if (state == IN_STRING)
        printf("Unclosed string literal\n");

    if (state == IN_CHAR)
        printf("Unclosed character literal\n");

    if (state == IN_BLOCK_COMMENT)
        printf("Unclosed block comment\n");

    while (top >= 0)
        printf("Unmatched %c\n", pop());

    fclose(fp);
}
