/*
* File Name     : 170877_harsh_DR_module8_T006_8-1.c
* Description   : Rewrite the program cat from Chapter 7 using read, write, open, and close instead of their standard library equivalents.
                  Perform experiments to determine the relative speeds of the two versions.
* Author        : harsh_kerai
* Date          : 27/04/2025
*/

#include "header.h"
#include <stdint.h>
#include <stdio.h>

#define BUFSIZE 8192

        void stdio_cat(FILE * fp)
        {
                char buf[BUFSIZE];
                size_t n;

                while ((n = fread(buf, 1, BUFSIZE, fp)) > 0)
                {
                        fwrite(buf, 1, n, stdout);
                }
        }

        void std_lib(int argc, char *argv[])
        {
                FILE *fp;

                if (argc == 1)
                {
                        stdio_cat(stdin);
                }
                else
                {
                        for (int8_t i = 1; i < argc; i++)
                        {
                                fp = fopen(argv[i], "r");
                                if (fp == NULL)
                                {
                                        perror("fopen");
                                        continue;
                                }
                                stdio_cat(fp);
                                fclose(fp);
                        }
                }
                return;
        }
