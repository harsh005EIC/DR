/*
* File Name     : 170877_harsh_DR_module8_T006_8-1.c
* Description   : Rewrite the program cat from Chapter 7 using read, write, open, and close instead of their standard library equiva>
                  Perform experiments to determine the relative speeds of the two versions.
* Author        : harsh_kerai
* Date          : 27/04/2025
*/

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#define BUFSIZE 8192

        void sys_cat(int8_t fd)
        {
                char buf[BUFSIZE];
                ssize_t n, w, total;

                while (1)
                {
                        n = read(fd, buf, BUFSIZE);

                        if (n == 0)
                                break;

                        if (n < 0)
                        {
                                if (errno == EINTR)
                                        continue;
                                perror("read");
                                break;
                        }

                        total = 0;
                        while (total < n)
                        {
                                w = write(STDOUT_FILENO, buf + total, n - total);
                                if (w <= 0)
                                {
                                        perror("write");
                                        return;
                                }
                                total += w;
                        }
                }
        }

        void sys_call(int argc, char *argv[])
        {
                int8_t fd;

                if (argc == 1)
                {
                        sys_cat(STDIN_FILENO);
                        return;
                }

                for (int8_t i = 1; i < argc; i++)
                {
                        fd = open(argv[i], O_RDONLY);
                        if (fd < 0)
                        {
                                perror("open");
                                continue;
                        }

                        sys_cat(fd);
                        close(fd);
                }

                return;
        }
