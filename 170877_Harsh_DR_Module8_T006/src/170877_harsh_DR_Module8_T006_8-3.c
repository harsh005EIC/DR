/*
 * File Name     : 170877_harsh_DR_module8_T006_8-3.c
 * Description   : Design and write _flushbuf, fflush, and fclose
 * Author        : harsh_kerai
 * Date          : 28/04/2025
 */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

        typedef struct _iobuf
        {
                int16_t cnt;
                char *ptr;
                char *base;
                int8_t flag;
                int8_t fd;
        } FILE;

        enum _flags
        {
                _READ = 01,
                _WRITE = 02,
                _UNBUF = 04,
                _EOF = 010,
                _ERR = 020
        };

        FILE _iob[OPEN_MAX] = {
            {0, NULL, NULL, _READ, 0},
            {0, NULL, NULL, _WRITE, 1},
            {0, NULL, NULL, _WRITE, 2}
        };

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

        FILE *fopen1(char *name, char *mode)
        {
                int8_t fd;
                FILE *fp;

                for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
                        if (!(fp->flag & (_READ | _WRITE)))
                                break;

                if (fp >= _iob + OPEN_MAX)
                        return NULL;

                if (*mode == 'w')
                        fd = creat(name, 0666);
                else
                        return NULL;

                if (fd == -1)
                        return NULL;

                fp->fd = fd;
                fp->cnt = 0;
                fp->base = NULL;
                fp->ptr = NULL;
                fp->flag = _WRITE;

                return fp;
        }

        int8_t _flushbuf(int16_t c, FILE *fp)
        {
                int16_t bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
                int16_t n;

                if (!(fp->flag & _WRITE))
                        return EOF;

                if (fp->base == NULL)
                {
                        fp->base = (char *)malloc(bufsize);
                        if (fp->base == NULL)
                        {
                                fp->flag |= _ERR;
                                return EOF;
                        }
                        fp->ptr = fp->base;
                }

                if (fp->ptr != fp->base)
                {
                        n = write(fp->fd, fp->base, fp->ptr - fp->base);
                        if (n != (fp->ptr - fp->base))
                        {
                                fp->flag |= _ERR;
                                return EOF;
                        }
                }

                fp->ptr = fp->base;
                fp->cnt = bufsize - 1;

                *fp->ptr++ = c;

                return c;
        }

        int16_t putc1(int16_t c, FILE *fp)
        {
                if (--fp->cnt >= 0)
                        return (*fp->ptr++ = c);
                else
                        return _flushbuf(c, fp);
        }

        int8_t fflush1(FILE * fp)
        {
                if (!(fp->flag & _WRITE) || fp->base == NULL)
                        return 0;

                int16_t n = write(fp->fd, fp->base, fp->ptr - fp->base);
                if (n != (fp->ptr - fp->base))
                {
                        fp->flag |= _ERR;
                        return EOF;
                }

                fp->ptr = fp->base;
                fp->cnt = BUFSIZ - 1;

                return 0;
        }

        int8_t fclose1(FILE * fp)
        {
                fflush1(fp);

                if (fp->base)
                        free(fp->base);

                close(fp->fd);

                fp->ptr = NULL;
                fp->base = NULL;
                fp->cnt = 0;
                fp->flag = 0;

                return 0;
        }

        int16_t getch()
        {
                char c;
                return (read(0, &c, 1) == 1) ? c : EOF;
        }

        void flushbuf_fflush_fclose(int argc, char *argv[])
        {
                if (argc < 2)
                        return;

                FILE *fp;
                int16_t c;

                fp = fopen1(argv[1], "w");
                if (fp == NULL)
                        return;

                while ((c = getch()) != EOF)
                        putc1(c, fp);

                fclose1(fp);
        }
