/*
* File Name     : 170904_harsh_DR_module4_T006_4-8.c
* Description   : Suppose that there will never be more than one character of pushback. Modify getch and ungetch
		  accordingly.
* Author        : harsh_kerai
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

#define MAXOP   100
#define NUMBER  '0'
#define MAXVAL  100

int8_t sp = 0;
double val[MAXVAL];

int8_t buf = EOF;

int16_t getch(void)
{
	int8_t c;

	if (buf != EOF){
	c = buf;
	buf = EOF;
	return c;
	}
	else
        return getchar();
}

void ungetch(int16_t c)
{
	if (buf != EOF)
	printf("ungetch: too many characters\n");
	else
	buf = c;
}


int getop(char s[])
{
	int8_t i = 0, c, next;
	while ((s[0] = c = getch()) == ' ' || c == '\t');

	s[1] = '\0';

	/* check for minus sign */

	if (c == '-') {
	next = getch();

	if (!isdigit(next) && next != '.') {
		ungetch(next);
		return '-';
        }

        s[++i] = next;
        c = next;
	}

	if (!isdigit(c) && c != '.')
        return c;

	if (isdigit(c))
	while (isdigit(s[++i] = c = getch()));

	if (c == '.')
		while (isdigit(s[++i] = c = getch()));

	s[i] = '\0';

	if (c != EOF)
	ungetch(c);

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
	else{
		printf("error: stack empty\n");
	return 0.0;
	}
}

void Modify_getch_ungetch(void)
{
int16_t type;
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
                printf("error: zero divisor\n");
            break;

        case '%':

            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else
                printf("error: zero divisor\n");
            break;

        case '\n':
            printf("\t%.8g\n", pop());
            break;

        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
}
