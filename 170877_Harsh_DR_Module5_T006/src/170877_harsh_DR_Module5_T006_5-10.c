/*
* File Name     : 170877_harsh_DR_module5_T006_5-10.c
* Description   : Write the program expr, which evaluates a reverse Polish expression from the command line, where each operator
	          or operand is a separate argument.
* Author        : harsh_kerai
* Date          : 01/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAXSTACK 100

	double value[MAXSTACK];
	int16_t stackp = 0;

	void push_stack(double f)
	{
    	   if(stackp < MAXSTACK)
        	value[stackp++] = f;
    	   else
        	printf("Error: stack full\n");
	}

	double pop_stack(void)
	{
		if(stackp > 0)
	   	 return value[--stackp];
		else{
	   	 printf("Error: stack empty\n");
		 return 0.0;
		}
	}

	void rpn_cl(int argc, char *argv[])
	{
	  int16_t i;
	  double op2;

	  stackp = 0;

		if(argc < 2){
			  printf("Usage: ./bin/main.out num num operator ...\n");
	 		  return;
		}

	for(i = 1; i < argc; i++){

		if(strcmp(argv[i], "+") == 0){
	  		if(stackp < 2){
				printf("not enough operands\n");
 				return;
	  		}
			push_stack(pop_stack() + pop_stack());
        	}

		else if(strcmp(argv[i], "*") == 0){
	   		if(stackp < 2){
				printf("not enough operands\n");
				return;
	   		}
	   		push_stack(pop_stack() * pop_stack());
        	}

		else if(strcmp(argv[i], "-") == 0){
            		if(stackp < 2){
				printf("not enough operands\n");
				return;
            		}
			op2 = pop_stack();
			push_stack(pop_stack() - op2);
        	}

		else if(strcmp(argv[i], "/") == 0){
	   		if(stackp < 2){
				printf("not enough operands\n");
				return;
	   		}

            		op2 = pop_stack();
           		if(op2 != 0.0)
                		push_stack(pop_stack() / op2);
            		else{
				printf("division by zero\n");
				return;
            		}
        	}

		else{
			push_stack(atof(argv[i]));
        	}
	}

		if(stackp == 1)
			printf("Result = %.2f\n", pop_stack());
		else
			printf("Error: invalid expression\n");
	}
