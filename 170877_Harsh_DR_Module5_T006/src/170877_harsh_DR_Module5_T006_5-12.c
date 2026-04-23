/*
* File Name     : 170877_harsh_DR_module5_T006_5-11.c
* Description   : Modify the program entab and detab (written as exercises in Chapter 1) to accept a list of tab stops as a>
                  Use the default tab settings if there are no arguments.
* Author        : harsh_kerai
* Date          : 06/04/2025
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void entab(int start, int step);
void detab(int start, int step);

	void entab_detab_shorthand(int argc,char *argv[])
	{
		int start = 0;
		int step = 8;

		if(argc >= 2){
			if(strcmp(argv[1], "en") != 0 && strcmp(argv[1], "de") != 0)
			{
				printf("Invalid mode (use en/de)\n");
				return;
			}

			if(argc >= 3)
			start = atoi(argv[2] + 1);

			if(argc >= 4)
			step = atoi(argv[3] + 1);
		}

	if(argc < 2)
	{
		char *lines[1000];
		int count = 0;
		char buffer[1024];

		while(fgets(buffer, sizeof(buffer), stdin))
		{
			lines[count] = strdup(buffer);
			count++;
		}

		int start_line = (count > 10) ? count - 10 : 0;

		for(int i = start_line; i < count; i++)
 			printf("%s", lines[i]);

	return;
	}

	if(strcmp(argv[1], "en") == 0)
		entab(start, step);
	else
		detab(start, step);

	return;
	}


	void entab(int start, int step)
	{
		int c, col = 0, space_count = 0;

		while((c = getchar()) != EOF){
			if(c == ' '){
            			space_count++;
            			col++;

        	    		if(col >= start && (col - start) % step == 0){
                			putchar('#');
                			space_count = 0;
            			}
			}

			else
			{
				while (space_count > 0)
				{
					putchar('*');
					space_count--;
				}
				putchar(c);

            			if(c == '\n')
					col = 0;
				else
					col++;
			}
    		}
	}

	void detab(int start, int step)
	{
		int c, col = 0;

		while((c = getchar()) != EOF){
			if(c == '\t'){
				int spaces;

				if(col < start)
					spaces = start - col;
				else
					spaces = step - ((col - start) % step);

				for(int i = 0; i < spaces; i++){
					putchar('*');
				}

			col += spaces;
			}
			else
			{
				putchar(c);

				if(c == '\n')
					col = 0;
				else
					col++;
			}
		}
	}

