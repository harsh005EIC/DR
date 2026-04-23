/*
* File Name     : 170904_harsh_DR_module4_T006_4-4.c
* Description   : Add the commands to print the top elements of the stack without popping, to duplicate it, and to swap the top
		  two elements. Add a command to clear the stack
* Author        : harsh_kerai
* Created       : 03-02-2026
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXOP   100
#define NUMBER  '0'
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];
int next = 1;

void print_stack(void)
{
    if (sp == 0) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");
    for (int i = 0; i < sp; i++)
        printf("%.8g ", val[i]);

    printf("\n");
}

int getop(char s[])
{
 int i = 0, c;
 while ((s[0] = c = getchar()) == ' ' || c == '\t');
 s[1] = '\0';

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
	printf("Error: stack empty\n");
	return 0.0;
	}
}
void print_swap_clear_stack(void)
{
	int type;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
	switch(type){

		case NUMBER:
		push(atof(s));
                break;

		case '?': {
		int count = 1;

		char temp[MAXOP];
		int t = getop(temp);

		if (t == NUMBER) {
		count = atoi(temp);
		}

		else {
		ungetc(t, stdin);
		}

		if (sp == 0) {
		printf("Error: stack empty\n");
		break;
		}

    if (count > sp)
        count = sp;

    for (int i = sp - count; i < sp; i++)
        printf("%.8g\n", val[i]);

    break;
}

		case 'd':
		if (sp > 0){
		push(val[sp-1]);
		}
		else
		printf("Error: stack empty\n");
		break;

		case 's':
		if (sp > 1) {
		double temp = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = temp;
		}
		else {
		printf("not enough elements\n");
		}
		break;

		case 'c':
		sp = 0;
		break;

		case '\n':
		print_stack();
		sp = 0;
            	printf("\n");
            	break;

		default:
                printf("unknown command %s\n", s);
                break;
	}
	}
}
