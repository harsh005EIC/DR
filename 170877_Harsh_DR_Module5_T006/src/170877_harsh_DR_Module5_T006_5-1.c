/*
* File Name     : 170877_harsh_DR_module5_T006_5-1.c
* Description   : As written, getint treats a + or - not followed by a digit as a valid representation of zero.
		  Fix it to push such a character back on the input.
* Author        : harsh_kerai
*Date		: 27/03/2026
*/

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int8_t bufp = 0;

int16_t getch(void)
{
	if (bufp > 0)
	  return buf[--bufp];
	else
	  return getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
	  printf("ungetch: too many characters\n");
	else
	  buf[bufp++] = c;
}

int8_t getint(int8_t *pn)
{
	int16_t c,sign,next;
	int8_t invalid = 0;
	while(isspace(c = getch()));

	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
	   while(c != '\n' && c != EOF)
                 c = getch();

        return 0;
	}

	sign=(c == '-') ? -1 : 1;

	if(c == '+' || c == '-'){

	next = getch();
        if (!isdigit(next)) {
            return 0;
        }
        c = next;
	}

	*pn=0;
	while(1){
	  if(isdigit(c)){
	  *pn = 10 * (*pn) + (c - '0');
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

	*pn = *pn * sign;

	if(c != EOF){
	ungetch(c);
	}

return c;
}

void change_getint(void)
{
	int8_t n, status;

	printf("Enter numbers:\n");

	while((status = getint(&n)) != EOF){
	  if(status == 0){
	    printf("Not a number\n");
	    break;
          }
	  else{
	    printf("Number: %d\n", n);
	  }
	}

printf("End of input\n");
return;
}

