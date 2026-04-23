/*
* File Name     : 170904_harsh_DR_module4_T006_4-3.c
* Description   : Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator
		  and provisions for negative numbers.
* Author        : harsh_kerai
* Created       : 03-02-2026
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXOP   100
#define NUMBER  '0'
#include <ctype.h>
#define MAXVAL 100

int8_t sp = 0;
double val[MAXVAL];

int getop(char s[])
{
	int8_t i = 0, c, next;

	while ((s[0] = c = getchar()) == ' ' || c == '\t');
	s[1] = '\0';

	if (c == '-') {
	        next = getchar();

        if (!isdigit(next) && next != '.') {
            ungetc(next,stdin);
            return '-';
        }

        	s[++i] = next;
        	c = next;
	}

	if (!isdigit(c) && c != '.')
	return c;

	if (isdigit(c))
		while (isdigit(s[++i] = c = getchar()));

	if (c == '.')
	       while (isdigit(s[++i] = c = getchar()));

    s[i] = '\0';

    if (c != EOF)
        ungetc(c,stdin);

    return NUMBER;
}

void push(double f)
{
if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full\n");
}
double pop(void)
{
 if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void reverse_polish_notation(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;

        case '+':
            push(pop() + pop());
            break;

        case '*':
            push(pop() * pop());
            break;

        case '-':
            op2 = pop();
            push(pop() - op2);
            break;

        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("zero divisor\n");
            break;

        case '\n':
            printf("\t%.8g\n", pop());
            break;

	case '%':
    		op2 = pop();
         	if (op2 != 0.0)
		push((int)pop() % (int)op2);
		else
		printf("zero divisor\n");
	    break;

        default:
            printf("unknown command %s\n", s);
            break;
        }
    }
}
