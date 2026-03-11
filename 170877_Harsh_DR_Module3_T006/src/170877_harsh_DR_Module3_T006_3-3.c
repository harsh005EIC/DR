/*
* File Name     : 170904_harsh_DR_module2_T006_3-3.c
* Description   : Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into the equivalent
		  complete list abc...xyz in s2. Allow for letters of either case and digits and be prepared to handle cases like
		  a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
* Author        : harsh_kerai
* Created       : 25-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include"header.h"


void print_characters(char prev,char next){
        if((prev >= 'A' && prev<= 'Z') && (next >='A' && next <= 'Z'))
        {
         if(prev <= next)
         {
                while(prev <= next){
                printf("%c",prev);
                prev++;
                }

         }
         else
         {
            while(prev >= next){
                printf("%c",prev);
                prev--;
                }
         }
        }

        else if((prev >= 'a' && prev <= 'z') && (next >='a' && next <= 'z'))
        {
         if(prev <= next)
         {
            while(prev <= next){
                printf("%c",prev);
                prev++;
                }
         }
         else
         {
            while(prev >= next){
                printf("%c",prev);
                prev--;
                }
         }
        }

         else if((prev >= '0' && prev <= '9') && (next >='0' && next <= '9'))
        {
         if(prev <= next)
         {
                while(prev <= next){
                printf("%c",prev);
                prev++;
                }
         }
         else
         {
            while(prev >= next){
                printf("%c",prev);
                prev--;
                }
         }
        }
        else{
        printf("%c-%c",prev,next);
        }
}

void expands(void){
char repeat;
do{

        char line[1000]="";
        int16_t length;
	int8_t index=0;
        while(fgets(line,sizeof(line),stdin) != NULL){
        length=strlen(line);

        if(line[length-1] == '\n')
        line[--length]='\0';


        while(line[length-1] == '-')
        {
        line[--length]='\0';
        }

	while(line[index] == '-')
	{
	index++;
	}
        char prev;
        char next;
	char prev_next;

         for(int16_t i=index;line[i] != '\0';i++)
	 {

                if(line[i] == '-')
                {
		prev=line[i-1];
		while(line[i+1] == '-')
		{
		i++;
		}
                next=line[i+1];
                i++;

			if(prev_next == prev){
			prev++;
			}
                	print_characters(prev,next);

                }

                else{
                        if(line[i+1] == '-')
                        continue;

                printf("%c",line[i]);
                }
		prev_next=next;
          }
	prev_next=' ';
	index=0;
        }
clearerr(stdin);
printf("\nDo you want to run again? (y/n): ");
scanf(" %c", &repeat);
getchar();
}while(repeat == 'y' || repeat == 'Y');
}
