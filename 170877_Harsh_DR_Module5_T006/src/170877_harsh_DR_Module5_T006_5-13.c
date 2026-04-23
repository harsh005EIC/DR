/*
* File Name     : 170877_harsh_DR_module5_T006_5-13.c
* Description   : Write the program tail, which prints the last n lines of its input. By default, n is set to 10, let us say,
		  but it can be changed by an optional argument so that tail -n prints the last n lines. The program should
		  behave rationally no matter how unreasonable the input or the value of n. Write the program so it makes the
		  best use of available storage; lines should be stored as in the sorting program of Section 5.6, not in a
		  two-dimensional array of fixed size.
* Author        : harsh_kerai
* Date          : 08/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAXLINE 1000

	char *read_line(void)
	{
		char temp[MAXLINE];
		if(fgets(temp, MAXLINE, stdin) == NULL)
			return NULL;

		int16_t len = strlen(temp);
		char *line = (char *)malloc(len + 1);

		if (line == NULL)
		{
			printf("Memory allocation failed\n");
			exit(1);
		}

		strcpy(line, temp);
		return line;
	}

	void tail_lines(int argc, char *argv[]){
	int16_t n = 10;

		if(argc == 2)
		{
			if (argv[1][0] == '-')
			{
				n = atoi(&argv[1][1]);
				if(n <= 0)
				{
					printf("Invalid value of n. Using default 10\n");
					n = 10;
				}
			}
		}

		char **buffer = (char **)malloc(n * sizeof(char *));

		if(buffer == NULL){
			printf("Memory allocation failed\n");
			return;
		}

		int16_t count = 0;
		char *line;

		while((line = read_line()) != NULL)
		{
			if(buffer[count % n] != NULL)
				free(buffer[count % n]);

			buffer[count % n] = line;
			count++;
		}

		int16_t start = (count > n) ? count - n : 0;

		for(int16_t i = start; i < count; i++) {
			printf("%s", buffer[i % n]);
		}

		int16_t limit = (count < n) ? count : n;

		for(int16_t i = 0; i < limit; i++) {
			free(buffer[i]);
		}

		free(buffer);

	return;
	}
