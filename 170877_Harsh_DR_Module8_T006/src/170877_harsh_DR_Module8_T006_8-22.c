/*
* File Name     : 170877_harsh_DR_module8_T006_8-1.c
* Description   : Rewrite fopen and _fillbuf with fields instead of explicit bit operations. Compare code size and execution
                  speed.
* Author        : harsh_kerai
* Date          : 28/04/2025
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>

#define BUFSIZE 1024

        typedef struct
        {
                int16_t cnt;
                char *ptr;
                char *base;
                int8_t fd;

                struct
                {
                        unsigned read : 1;
                        unsigned write : 1;
                        unsigned unbuf : 1;
                        unsigned eof : 1;
                        unsigned err : 1;
                } flag;

        } FILE2;

        FILE2 *fopen2(char *name, char *mode)
        {
                int8_t fd;
                FILE2 *fp;

                if ((fp = malloc(sizeof(FILE2))) == NULL)
                        return NULL;

                if (*mode == 'r')
                        fd = open(name, O_RDONLY);
                else
                {
                        free(fp);
                        return NULL;
                }

                if (fd == -1)
                {
                        free(fp);
                        return NULL;
                }

                fp->fd = fd;
                fp->cnt = 0;
                fp->base = NULL;
                fp->ptr = NULL;

                fp->flag.read = 1;
                fp->flag.write = 0;
                fp->flag.unbuf = 0;
                fp->flag.eof = 0;
                fp->flag.err = 0;

                return fp;
        }

        int16_t fillbuf2(FILE2 * fp)
        {
                int16_t bufsize;

                if (!fp->flag.read || fp->flag.eof || fp->flag.err)
                        return EOF;
                if (fp->cnt <= 0)
                {

                        bufsize = fp->flag.unbuf ? 1 : BUFSIZE;

                        if (fp->base == NULL)
                                if ((fp->base = malloc(bufsize)) == NULL)
                                        return EOF;

                        fp->ptr = fp->base;
                        fp->cnt = read(fp->fd, fp->ptr, bufsize);

                        if (fp->cnt <= 0)
                        {
                                if (fp->cnt == 0)
                                        fp->flag.eof = 1;
                                else
                                        fp->flag.err = 1;
                                return EOF;
                        }
                }

                fp->cnt--;
                return (unsigned char)*fp->ptr++;
        }

        void bit_field(int argc, char *argv[])
        {
                int16_t c;

                if (argc < 2)
                {
                        printf("Usage: %s filename\n", argv[0]);
                        return;
                }

                clock_t start, end;
                double time_bitfield;

                FILE2 *fp2 = fopen2(argv[1], "r");
                start = clock();
                while ((c = fillbuf2(fp2)) != EOF)
                {
                        putchar(c); // print file content
                }
                end = clock();
                time_bitfield = (double)(end - start) / CLOCKS_PER_SEC;

                printf("\nBit-field time : %f sec\n", time_bitfield);
                return;
        }
