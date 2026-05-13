/*
 * File Name     : 170877_harsh_DR_module8_T006_8-4.c
 * Description   : The standard library function.
 * Author        : harsh_kerai
 * Date          : 04/05/2025
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define EOF (-1)
#define BUFSIZ 8192
#define OPEN_MAX 20

        typedef struct _iobuf
        {
                int cnt;
                char *ptr;
                char *base;
                int flag;
                int fd;
        } FILE1;

        enum _flags
        {
                _READ = 01,
                _WRITE = 02,
                _UNBUF = 04,
                _EOF = 010,
                _ERR = 020
        };

        FILE1 _iob[OPEN_MAX] = {{0, NULL, NULL, _READ, 0}, {0, NULL, NULL, _WRITE, 1}, {0, NULL, NULL, _WRITE, 2}};

#define stdin1 (&_iob[0])
#define stdout1 (&_iob[1])
#define stderr1 (&_iob[2])

        /* ---------- fillbuf ---------- */
        int _fillbuf(FILE1 * fp)
        {
                int bufsize;

                if (!(fp->flag & _READ) || (fp->flag & (_EOF | _ERR)))
                        return EOF;

                bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

                if (fp->base == NULL)
                        if ((fp->base = (char *)malloc(bufsize)) == NULL)
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

                fp->cnt--;
                return (unsigned char)*fp->ptr++;
        }

        /* ---------- flushbuf ---------- */
        int _flushbuf(int c, FILE1 *fp)
        {
                int n;
                int bufsize;

                if (!(fp->flag & _WRITE))
                        return EOF;

                bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

                if (fp->base == NULL)
                        if ((fp->base = (char *)malloc(bufsize)) == NULL)
                        {
                                fp->flag |= _ERR;
                                return EOF;
                        }

                if (fp->ptr != NULL && fp->base != NULL)
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

                if (c != EOF)
                        *fp->ptr++ = c;

                return c;
        }

        /* ---------- fopen ---------- */
        FILE1 *fopen1(char *name, char *mode)
        {
                int fd;
                FILE1 *fp;

                for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
                        if (!(fp->flag & (_READ | _WRITE)))
                                break;

                if (fp >= _iob + OPEN_MAX)
                        return NULL;

                if (*mode == 'r')
                        fd = open(name, O_RDONLY);
                else if (*mode == 'w')
                        fd = creat(name, 0666);
                else if (*mode == 'a')
                {
                        if ((fd = open(name, O_WRONLY, 0)) == -1)
                                fd = creat(name, 0666);
                        lseek(fd, 0L, SEEK_END);
                }
                else
                        return NULL;

                if (fd == -1)
                        return NULL;

                fp->fd = fd;
                fp->cnt = 0;
                fp->base = NULL;
                fp->ptr = NULL;
                fp->flag = (*mode == 'r') ? _READ : _WRITE;

                return fp;
        }

        /* ---------- fflush ---------- */
        int fflush1(FILE1 * fp)
        {
                if (fp == NULL)
                        return EOF;

                if (fp->flag & _WRITE)
                        return _flushbuf(EOF, fp);

                return 0;
        }

        /* ---------- fclose ---------- */
        int fclose1(FILE1 * fp)
        {
                int rc = fflush1(fp);

                if (fp->base != NULL)
                        free(fp->base);

                fp->ptr = NULL;
                fp->base = NULL;
                fp->cnt = 0;
                fp->flag = 0;

                return (close(fp->fd) == -1) ? EOF : rc;
        }

        /* ---------- _fseek ---------- */
        int _fseek(FILE1 * fp, long offset, int origin)
        {
                long pos;

                if (fp->flag & _READ)
                {
                        if (origin == SEEK_CUR && fp->base != NULL)
                                offset -= fp->cnt;
                }
                else if (fp->flag & _WRITE)
                {
                        if (fflush1(fp) == EOF)
                                return -1;
                }

                pos = lseek(fp->fd, offset, origin);
                if (pos == -1)
                        return -1;

                fp->cnt = 0;
                fp->ptr = fp->base;
                fp->flag &= ~(_EOF | _ERR);

                return 0;
        }

        /* ---------- getc ---------- */
        int getc1(FILE1 * fp)
        {
                return (--fp->cnt >= 0) ? (unsigned char)*fp->ptr++ : _fillbuf(fp);
        }

        /* ---------- putc ---------- */
        int putc1(int c, FILE1 *fp)
        {
                return (--fp->cnt >= 0) ? *fp->ptr++ = c : _flushbuf(c, fp);
        }

        /* ---------- MAIN ---------- */
        void fseek_function(int argc, char *argv[])
        {
                FILE1 *fp;
                int c, choice;
                long offset;
                int origin;

                if (argc < 2)
                {
                        printf("Usage: %s filename\n", argv[0]);
                        return;
                }

                fp = fopen1(argv[1], "r");
                if (fp == NULL)
                {
                        printf("File open error\n");
                        return;
                }

                printf("Enter offset: ");
                scanf("%ld", &offset);

                printf("Choose origin:\n");
                printf("0 -> SEEK_SET\n1 -> SEEK_CUR\n2 -> SEEK_END\n");
                scanf("%d", &choice);

                if (choice == 0)
                        origin = SEEK_SET;
                else if (choice == 1)
                        origin = SEEK_CUR;
                else if (choice == 2)
                        origin = SEEK_END;
                else
                {
                        printf("Invalid choice\n");
                        fclose1(fp);
                        return;
                }

                if (_fseek(fp, offset, origin) != 0)
                {
                        printf("Seek error\n");
                        fclose1(fp);
                        return;
                }

                printf("\nFile content after seek:\n\n");

                while ((c = getc1(fp)) != EOF)
                        putc1(c, stdout1);

                fflush1(stdout1);

                fclose1(fp);
                return;
        }
