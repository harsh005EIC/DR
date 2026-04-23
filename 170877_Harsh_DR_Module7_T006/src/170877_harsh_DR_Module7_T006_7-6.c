/*
* File Name     : 170877_harsh_DR_module7_T006_7-6.c
* Description   : Write a program to compare two files, printing the first line where they differ.
* Author        : harsh_kerai
* Date          : 22/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

	void file_compare(int argc, char *argv[])
	{
		if(argc != 3)
		{
			printf("Usage: %s file1 file2\n", argv[0]);
			return;
		}

		FILE *fp1 = fopen(argv[1], "r");
		FILE *fp2 = fopen(argv[2], "r");

		if(fp1 == NULL || fp2 == NULL)
		{
			printf("Error opening files\n");
			return;
		}

		char line1[MAXLINE], line2[MAXLINE];
		int lineNo = 1;

		while(1)
		{
			char *res1 = fgets(line1, MAXLINE, fp1);
			char *res2 = fgets(line2, MAXLINE, fp2);

			if(res1 == NULL && res2 == NULL)
			{
				printf("Files are identical\n");
				break;
			}

			if(res1 == NULL || res2 == NULL || strcmp(line1, line2) != 0)
			{
				printf("Files differ at line %d:\n", lineNo);
				printf("File1: %s", res1 ? line1 : "EOF\n");
				printf("File2: %s", res2 ? line2 : "EOF\n");

				break;
			}

			lineNo++;
		}

		fclose(fp1);
		fclose(fp2);

		return;
	}
