/*
* File Name     : 170877_harsh_DR_module5_T006_5-11.c
* Description   : Modify the program entab and detab (written as exercises in Chapter 1) to accept a list of tab stops as arguments.
		  Use the default tab settings if there are no arguments.
* Author        : harsh_kerai
* Date          : 06/04/2025
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void entab(int n);
void detab(int n);

	void entab_detab_cl(int argc, char *argv[]){
		if(argc < 2){
			printf("Not enough arguments\n");
			return;
    		}

		if(argc == 2){
			printf("Usage: ./Exercise_5_11 [en/de] [n]\n");
			return;
		}

		int n=atoi(argv[2]);

		if(n <= 0){
			printf("Invalid Entry!!!\n");
			return;
		}

		if(strcmp(argv[1], "en") == 0){
			entab(n);
		}

		else if(strcmp(argv[1], "de") == 0) {
			detab(n);
		}

		else{
			printf("Invalid Entry!!!\n");
		}

		return;
	}

/*
* File Name     : 170877_harsh_DR_module5_T006_5-11.c
* Description   : function for entab,which replacing space by '\t'.
* Author        : harsh_kerai
* Date          : 06/04/2025
*/

	void entab(int n){

	int16_t c;
	int8_t space=0;
	int8_t character=0;

	while((c=getchar()) != EOF){
		if(c == ' '){
			space++;
			character++;

			if(character % n == 0)
			{
				putchar('\\');
				putchar('t');
				space=0;
 			}
		}

		else
		{
			while(space > 0)
			{
				putchar('*');
				space--;
			}
			putchar(c);

			if(c=='\n')
			{
				character=0;
			}

			else
			{
				character++;
			}
		}
	}
	}

/*
* File Name     : 170877_harsh_DR_module5_T006_5-11.c
* Description   : function for detab,which replacing '\t' by space.
* Author        : harsh_kerai
* Date          : 06/04/2025
*/
	void detab(int n){
		int16_t c;
		int8_t space;
		int8_t tab=n;
		int16_t character=0;

		while((c=getchar()) != EOF)
		{
			if(c == '\t')
			{
				space = tab - (character % tab);
				for(int8_t i=0;i<space;i++){
				putchar('*');
				}

        		character=character+space;
			}

			else
			{
				putchar(c);
				if(c=='\n')
				{
					character=0;
				}
				else
					character++;
			}
		}
	}

