/*
* File Name     : 170877_harsh_DR_module5_T006_5-2.c
* Description   : Write a function getfloat, the floating-point analog of getint. What type does getfloat return as its function
		  value?
* Author        : harsh_kerai
* Date		: 30/03/2025
*/

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int8_t bufp = 0;

	int16_t getch(void)
	{
		if(bufp > 0)
	  	  return buf[--bufp];
		else
	          return getchar();
	}

	void ungetch(int c)
	{
    	  if(bufp >= BUFSIZE)
            printf("ungetch: too many characters\n");
    	  else
            buf[bufp++] = c;
	}

int8_t getf(double *pn)
{

	int16_t c, sign, next;
	double power = 1.0;
	int8_t invalid = 0;
	int8_t state = 1;
	int8_t decimalpoint=0;
	while (isspace(c = getch()));

	if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
	while (c != '\n' && c != EOF)
            c = getch();
        return 0;
	}

	sign=(c == '-') ? -1 : 1;

	if(c == '+' || c == '-'){
	  next = getch();
        if(!isdigit(next) && next != '.') {
          return 0;
        }

        c = next;
	}

	*pn=0;
	while(1){
	if(isdigit(c)){
          *pn = 10 * (*pn) + (c - '0');
	   if(decimalpoint == 1)
	   power *= 10;
          }

	else if(c == '.' && state == 1){
	decimalpoint = 1;
	state = 0;
	c = getch();
	continue;
	}
          else{
            if(c != '\n' && c != EOF && !isspace(c)){
              invalid = 1;
            }
            break;
          }
        c = getch();
	}

	if(invalid){
	  while (c != '\n' && c != EOF && !isspace(c))
	  c=getch();
        return 0;
        }

    *pn = (*pn / power) * sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

/* main-style function */
void getfloat(void)
{
    double n;
    int8_t status;

    printf("Enter floating numbers:\n");

    while ((status = getf(&n)) != EOF) {
        if (status == 0) {
            printf("Not a number\n");
        } else {
            printf("Number: %f\n", n);
        }
    }

    printf("End of input\n");
}
