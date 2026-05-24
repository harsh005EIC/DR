/*
* File Name     : 170877_harsh_DR_module4_T006_4-10.c
* Description   : RPN calculator using getline instead of getch/ungetch
* Author        : harsh_kerai
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

#define LINE 100
#define VAL 100
#define NUMBER '0'

int8_t sp = 0;
double val[VAL];

char line[LINE];
int8_t li = 0;

	void push(double f)
	{
	if (sp < VAL)
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

int16_t getop(char s[])
{
	int8_t i = 0;
	char c;

	while ((c = line[li]) == ' ' || c == '\t')
	li++;

   	c = line[li++];

	if (c == '\n' || c == '\0')
          return '\n';

	if (!isdigit(c) && c != '.' && c != '-')
	  return c;

	if (c == '-' && !isdigit(line[li]) && line[li] != '.')
          return '-';

	if (c == '-') {
	  s[i++] = c;
	  c = line[li++];
	}

	if (isdigit(c)) {
          s[i++] = c;
        while (isdigit(line[li]))
          s[i++] = line[li++];
	}

	if (line[li] == '.') {
          s[i++] = line[li++];
        while (isdigit(line[li]))
          s[i++] = line[li++];
	}

    s[i] = '\0';
    return NUMBER;
}

int16_t getline1(char s[], int lim)
{
int16_t c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
          s[i] = c;

	if(c == '\n')
          s[i++] = c;

	s[i] = '\0';

	return i;
}

void rpn_getline(void)
{
    int8_t type;
    double op2;
    char s[LINE];

    while (getline1(line, LINE) > 0) {

        li = 0;

        while ((type = getop(s)) != '\n') {

            switch (type) {

            case NUMBER:
                push(atof(s));
                break;

            case '+':
                push(pop() + pop());
                break;

            case '-':
                op2 = pop();
                push(pop() - op2);
                break;

            case '*':
                push(pop() * pop());
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

            default:
                printf("error: unknown command %s\n", s);
                break;
            }
        }

        printf("\t%.8g\n", pop());
    }
}
