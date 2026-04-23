/*
* File Name     : 170877_harsh_DR_module7_T006_7-8.c
* Description   : Write a program to print a set of files, starting each new one on a new page, with a title and a running page
                  count for each file.
* Author        : harsh_kerai
* Date          : 23/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXLINE 1000
#define PAGELEN 20

        void print_file(FILE * fp, char *filename);

        void print_files(int argc, char *argv[])
        {
                FILE *fp;

                if (argc < 2)
                {
                        printf("Usage: program file1 file2 ...\n");
                        return;
                }

                for (int i = 1; i < argc; i++)
                {
                        fp = fopen(argv[i], "r");
                        if (fp == NULL)
                        {
                                printf("Error: cannot open %s\n", argv[i]);
                                continue;
                        }

                        print_file(fp, argv[i]);
                        fclose(fp);
                }

                return;
        }

        void print_file(FILE * fp, char *filename)
        {
                char line[MAXLINE];
                int line_count = 0;
                int page = 1;

                printf("\f");
                printf("File: %s\t\tPage: %d\n\n", filename, page);

                while (fgets(line, MAXLINE, fp) != NULL)
                {
                        if (line_count == PAGELEN)
                        {
                                page++;
                                line_count = 0;
                                printf("\f");
                                printf("File: %s\t\tPage: %d\n\n", filename, page);
                        }

                        printf("%s", line);
                        line_count++;
                }
        }
