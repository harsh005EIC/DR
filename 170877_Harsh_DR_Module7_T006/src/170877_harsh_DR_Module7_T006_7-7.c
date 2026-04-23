/*
* File Name     : 170877_harsh_DR_module7_T006_7-7.c
* Description   : Modify the pattern finding program of Chapter 5 to take its input from a set of
                  named files or, if no files are named as arguments, from the standard input.
Should the file name be printed when a matching line is found?
* Author        : harsh_kerai
* Date          : 22/04/2025
*/

#include <stdio.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline_custom(char line[], int max);
int strindex(char source[], char searchfor[]);

        void find_keyword(int argc, char *argv[])
        {
                char line[MAXLINE];

                if (argc < 2)
                {
                        printf("Usage: find pattern [file ...]\n");
                        return;
                }

                char *pattern = argv[1];

                if(argc == 2)
                {
                        int lineno = 0;
                        while (getline_custom(line, MAXLINE) > 0)
                        {
                                lineno++;
                                if (strindex(line, pattern) >= 0)
                                {
                                        printf("stdin:%d:%s", lineno, line);
                                }
                        }
                }
                else
                {
                        for (int i = 2; i < argc; i++)
                        {
                                FILE *fp = fopen(argv[i], "r");
                                if (fp == NULL)
                                {
                                        printf("Error: Cannot open file %s\n", argv[i]);
                                        continue;
                                }

                                int lineno = 0;
                                while (fgets(line, MAXLINE, fp) != NULL)
                                {
                                        lineno++;
                                        if (strindex(line, pattern) >= 0)
                                        {
                                                printf("%s:%d:%s", argv[i], lineno, line);
                                        }
                                }
                                fclose(fp);
                        }
                }

        }

        int getline_custom(char s[], int lim)
        {
                int c, i = 0;

                while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
                {
                        s[i++] = c;
                }

                if (c == '\n')
                {
                        s[i++] = c;
                }

                s[i] = '\0';
                return i;
        }

        int strindex(char source[], char searchfor[])
        {
                int i, j, k;

                for (i = 0; source[i] != '\0'; i++)
                {
                        for (j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
                                ;
                        if (k > 0 && searchfor[k] == '\0')
                                return i;
                }
                return -1;
        }


