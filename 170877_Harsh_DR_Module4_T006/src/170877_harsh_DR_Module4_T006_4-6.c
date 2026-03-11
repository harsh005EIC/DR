/*
* File Name     : 170904_harsh_DR_module4_T006_4-6.c
* Description   : Add commands for handling variables. (It's easy to provide twenty-six variables with single-letter names.)
		  Add a variable for the most recently printed value.
* Author        : harsh_kerai
* Created       : 05-02-2026
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<stdint.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

int8_t sp=0;
double val[MAXVAL];

double alpha[26]={0};
double last = 0.0;
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
	int16_t i=0,c;
	while((s[0] = c = getchar()) == ' ' || c == '\t');
	s[1]='\0';

	if(!isdigit(c) && c != '.' && !isupper(c))
	return c;

	if(isupper(c)){
        s[0] = c;
        return c;
    	}

	if(isdigit(c))
        while(isdigit(s[++i] = c = getchar()));

	if(c == '.')
        while(isdigit(s[++i] = c = getchar()));

	s[i]='\0';

 	if(c != EOF)
        ungetc(c, stdin);

	return NUMBER;

}
void push(double f)
{
	if(sp<MAXVAL)
	val[sp++]=f;
	else
	printf("stack is full\n");
}

double pop(void)
{
	if(sp>0)
	return val[--sp];
	else{
	printf("stack is empty\n");
	return 0.0;
	}
}
void handling_variable(void)
{
int16_t type;
char s[MAXOP];
double op2;
int8_t var = -1;
	while((type = getop(s)) != EOF)
	{
	switch(type){

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
		if(op2 != 0.0)
                push(pop() / op2);
		else
                printf("error: zero divisor\n");
		break;

		case 'v':
		push(last);
		break;

		case 's':
		push(sin(pop()));
		break;

		case 'e':
		push(exp(pop()));
		break;

		case 'p':
		op2 = pop();
		push(pow(pop(), op2));
		break;

		case '=':
		    pop();
		    double value = pop();
    		    if(var >= 'A' && var <= 'Z'){
        	    alpha[var - 'A'] = value;
        		push(value);
    		    }
   		 break;

		case 'A': case 'B': case 'C': case 'D': case 'E':
        	case 'F': case 'G': case 'H': case 'I': case 'J':
        	case 'K': case 'L': case 'M': case 'N': case 'O':
        	case 'P': case 'Q': case 'R': case 'S': case 'T':
        	case 'U': case 'V': case 'W': case 'X': case 'Y':
        	case 'Z':
		var = type;
		push(alpha[type - 'A']);
		break;

		case '\n':
		last = pop();
		printf("\t%.8g\n", last);
		break;

		default:
		printf("unknown command %s\n", s);
		break;
	}
	}
}
