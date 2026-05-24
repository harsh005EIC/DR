/*
* File Name     : 170877_harsh_DR_module2_T006_3-2.c
* Description   : Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like
		  \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well,
		  converting escape sequences into the real characters.
* Author        : harsh_kerai
* Created       : 24-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include"header.h"

void escape(void)
{
char repeat;
do
{
        char line[1000]="";
	char long_line[1000]="";

	int8_t choose;

printf("Enter 0 if you want to convert character into escape sequences : \n");
printf("Enter 1 if you want to convert escape sequences into character : \n");

	scanf("%hhd",&choose);

switch(choose)
{
case 0:

        while (fgets(line, sizeof(line), stdin) != NULL)
        {
	 strcat(long_line,line);
	}
            for(int16_t i = 0; long_line[i] != '\0'; i++)
            {
                if(long_line[i] == '\t')
                {
                    putchar('\\');
                    putchar('t');
                }
                else if(long_line[i] == '\n')
                {
                    putchar('\\');
                    putchar('n');
                }
                else
                {
                    putchar(long_line[i]);
                }
            }
	break;
case 1:
	while (fgets(line, sizeof(line), stdin) != NULL)
        {
         strcat(long_line,line);
        }
	int8_t space=0;
	for(int16_t i=0;long_line[i] != '\0';i++){
		if(long_line[i] == '\\' && long_line[i+1] == 't')
		{
			while(space<8)
			{
			 putchar(' ');
			 space++;
			}
			i++;
			space=0;
		}
		else if(long_line[i] == '\\' && long_line[i+1] == 'n')
		{
		 putchar('\n');
		 i++;
		}
		 else
                {
                    putchar(long_line[i]);
                }
	}
	break;
}

clearerr(stdin);
printf("\nDo you want to run again? (y/n): "); 
scanf(" %c", &repeat);
getchar(); // clear buffer
}while(repeat == 'y' || repeat == 'Y');
}
