/*
* File Name     : 170877_harsh_DR_module8_T006_8-2.c
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

#define _READ 01
#define _WRITE 02
#define _UNBUF 04
#define _EOF 010
#define _ERR 020

        typedef struct
        {
                int16_t cnt;
                char *ptr;
                char *base;
                int8_t flag;
                int8_t fd;
        } FILE1;

        FILE1 *fopen1(char *name, char *mode)
        {
                int8_t fd;
                FILE1 *fp;

                if ((fp = malloc(sizeof(FILE1))) == NULL)
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
                fp->flag = _READ;

                return fp;
        }

        int16_t fillbuf1(FILE1 * fp)
        {
                int16_t bufsize;

                if ((fp->flag & (_READ)) == 0 || (fp->flag & (_EOF | _ERR)))
                        return EOF;

                if (fp->cnt <= 0)
                {

                        bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZE;

                        if (fp->base == NULL)
                                if ((fp->base = malloc(bufsize)) == NULL)
                                        return EOF;

                        fp->ptr = fp->base;
                        fp->cnt = read(fp->fd, fp->ptr, bufsize);

                        if (fp->cnt <= 0)
                        {
                                if (fp->cnt == 0)
                                        fp->flag |= _EOF;
                                else
                                        fp->flag |= _ERR;
                                fp->cnt = 0;
                                return EOF;
                        }
                }
                fp->cnt--;

                return (unsigned char)*fp->ptr++;
        }

        void bit_wise(int argc, char *argv[])
        {
                int16_t c;

                if (argc < 2)
                {
                        printf("Usage: %s filename\n", argv[0]);
                        return;
                }

                clock_t start, end;
                double time_bitwise;

                FILE1 *fp1 = fopen1(argv[1], "r");
                start = clock();
                while ((c = fillbuf1(fp1)) != EOF)
                        putchar(c);
                end = clock();
                time_bitwise = (double)(end - start) / CLOCKS_PER_SEC;

                printf("Bitwise time   : %f sec\n", time_bitwise);

                return;
        }
