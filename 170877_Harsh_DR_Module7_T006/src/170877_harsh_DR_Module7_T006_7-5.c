/*
* File Name     : 170877_harsh_DR_module7_T006_7-5.c
* Description   : Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf to do the input and number conversion.
* Author        : harsh_kerai
* Date          : 22/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define MAX 100

int16_t stack[MAX];
int8_t top = -1;

	void push(int val)
	{
		if(top >= MAX - 1)
		{
			printf("Stack overflow\n");
			exit(1);
		}
		stack[++top] = val;
	}

	int16_t pop()
	{
		if(top < 0)
		{
			printf("Stack underflow\n");
			exit(1);
		}
		return stack[top--];
	}

	int8_t isNumber(char *s)
	{
		int8_t i = 0;

		if(s[0] == '-')
		{
			if (s[1] == '\0') return 0;
			i = 1;
		}
		for(; s[i]; i++)
		{
			if(!isdigit(s[i]))
			return 0;
		}
		return 1;
	}

	void rpn_sscanf()
	{
		char input[1000];
		char token[100];
		int16_t n;

		printf("Enter RPN expression: ");
		fgets(input, sizeof(input), stdin);

		char *ptr = input;

		while(sscanf(ptr, "%s%hn", token, &n) == 1)
		{
			if(isNumber(token))
			{
				int16_t value;
				sscanf(token, "%hd", &value);
				push(value);
			}

			else if(strlen(token) == 1)
			{
				int16_t b = pop();
				int16_t a = pop();

				switch(token[0])
				{
					case '+': push(a + b); break;
					case '-': push(a - b); break;
					case '*': push(a * b); break;
					case '/':
						if(b == 0)
						{
							printf("Division by zero\n");
							exit(1);
						}
						push(a / b);
						break;
					case '%':
						if(b == 0)
						{
							printf("Modulo by zero error\n");
							exit(1);
						}
						push(a % b);
						break;

					default:
						printf("Invalid operator: %s\n", token);
						exit(1);
				}
			}
			else
			{
				printf("Invalid token: %s\n", token);
				exit(1);
			}

			ptr += n;
		}

		if(top == 0)
		{
			printf("Result = %d\n", pop());
		}
		else
		{
			printf("Invalid expression\n");
		}

		return;
	}

