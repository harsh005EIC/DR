/*
* File Name     : 170904_harsh_DR_module4_T006_4-5.c
* Description   : Add access to library functions like sin, exp, and pow.
		  By using in built library functions provided by <math.h> library.
		  One must create the commands for sin, exp and power operation.
		  It is the similar way which we used before for creating the commands for duplication, clear etc.
* Author        : harsh_kerai
* Created       : 05-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

int8_t sp=0;
double val[MAXVAL];

	void print_stack(void)
	{
		if(sp == 0){
		printf("stack is empty");
		return;
		}
		printf("Stack: ");
		for(int8_t i = 0; i<sp;i++)
		printf("%.8g ",val[i]);

		printf("\n");
	}

	int16_t getop(char s[])
	{
	int8_t i = 0,c;
	while((s[0] = c = getchar()) == ' ' || c == '\t');
	s[1] = '\0';

	if(!isdigit(c) && c != '.')
	return c;

	if(isdigit(c))
	while(isdigit(s[++i] = c = getchar()));

	if(c == '.')
	while(isdigit(s[++i] = c = getchar()));

	s[i] = '\0';
	if (c != EOF)
	ungetc(c,stdin);

	return NUMBER;
	}

void push(double f)
{
	if(sp<MAXVAL)
	val[sp++]=f;
	else
	printf("stack is full \n");
}

double pop(void)
{
	if(sp > 0)
	return val[--sp];
	else{
	printf("stack is empty\n");
	return 0.0;
	}
}
void sin_exp_pow_stack(void)
{
	int16_t type;
	char s[MAXOP];
	double op;

	while((type = getop(s)) != EOF){
		switch(type){

		case NUMBER:
		push(atof(s));
		break;

		case 's':
		push(sin(pop()));
    		break;

		case 'p':
		op = pop();
    		push(pow(pop(), op));
    		break;

		case 'e':
		push(exp(pop()));
		break;

		case 'c':
		sp=0;
		break;

		case '\n':
		printf("\t%.8g\n", pop());
		printf("\n");
		break;

		default:
		printf("unknown command %s",s);
		break;
		}
	}
}
