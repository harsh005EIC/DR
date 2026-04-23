/*
* File Name     : 170904_harsh_DR_module4_T006_4-11.c
* Description   : Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable.
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

int getop(char s[])
{
	int8_t i = 0, c;

	static int buf = EOF;

	if (buf!=EOF){
        c = buf;
        buf = EOF;
	}

	else{
        c = getchar();
	}

	while (c == ' ' || c == '\t')
	  c = getchar();

	s[0] = c;
	s[1] = '\0';

	if(!isdigit(c) && c != '.' && c != '-')
	return c;

	i = 0;

	if (c == '-') {
        int8_t next = getchar();

        if (!isdigit(next) && next != '.') {
            buf = next;
            return '-';
        }

	s[++i] = c = next;
	}

	if(isdigit(c)) {
		while (isdigit(c = getchar()))
		s[++i] = c;
	}

	if(c == '.') {
	  s[++i] = c;
        while (isdigit(c = getchar()))
          s[++i] = c;
	}

    s[++i] = '\0';

    if (c != EOF)
        buf = c;

    return NUMBER;
}
/* RPN calculator */
void modified_getop_wo_un_getch(void)
{
    int8_t type;
    double op2;
    char s[LINE];

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

