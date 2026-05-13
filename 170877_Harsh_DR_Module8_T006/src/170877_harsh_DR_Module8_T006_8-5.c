/*
 * File Name     : 170877_harsh_DR_module8_T006_8-5.c
 * Description   : Modify the fsize program to print the other information contained in the inode entry.
 * Author        : harsh_kerai
 * Date          : 04/05/2025
 */

#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_PATH 1024

        void fsize(char *name);
        void dirwalk(char *dir, void (*fcn)(char *));

        void fsize_function(int argc, char *argv[])
        {
                if (argc == 1)
                {
                        printf("No file is given\n");
                        return;
                }
                else
                {
                        while (--argc > 0)
                                fsize(*++argv);
                }
                return;
        }

        void fsize(char *name)
        {
                struct stat stbuf;

                if (stat(name, &stbuf) == -1)
                {
                        fprintf(stderr, "fsize: can't access %s\n", name);
                        return;
                }

                printf("File: %s\n", name);

                printf("Device ID     : %ld\n", (long)stbuf.st_dev);
                printf("Inode Number  : %ld\n", (long)stbuf.st_ino);

                printf("Type & Perm   : ");
                printf((S_ISDIR(stbuf.st_mode)) ? "d" : "-");
                printf((stbuf.st_mode & S_IRUSR) ? "r" : "-");
                printf((stbuf.st_mode & S_IWUSR) ? "w" : "-");
                printf((stbuf.st_mode & S_IXUSR) ? "x" : "-");
                printf((stbuf.st_mode & S_IRGRP) ? "r" : "-");
                printf((stbuf.st_mode & S_IWGRP) ? "w" : "-");
                printf((stbuf.st_mode & S_IXGRP) ? "x" : "-");
                printf((stbuf.st_mode & S_IROTH) ? "r" : "-");
                printf((stbuf.st_mode & S_IWOTH) ? "w" : "-");
                printf((stbuf.st_mode & S_IXOTH) ? "x" : "-");
                printf("\n");

                printf("Links         : %ld\n", (long)stbuf.st_nlink);

                struct passwd *pw = getpwuid(stbuf.st_uid);
                struct group *gr = getgrgid(stbuf.st_gid);

                printf("Owner         : %s\n", pw ? pw->pw_name : "unknown");
                printf("Group         : %s\n", gr ? gr->gr_name : "unknown");

                printf("Special Dev   : %ld\n", (long)stbuf.st_rdev);

                printf("Size (bytes)  : %ld\n", (long)stbuf.st_size);

                printf("Last Access   : %s", ctime(&stbuf.st_atime));
                printf("Last Modify   : %s", ctime(&stbuf.st_mtime));
                printf("Last Change   : %s", ctime(&stbuf.st_ctime));

                if (S_ISDIR(stbuf.st_mode))
                        dirwalk(name, fsize);
        }

        void dirwalk(char *dir, void (*fcn)(char *))
        {
                char name[MAX_PATH];
                struct dirent *dp;
                DIR *dfd;

                if ((dfd = opendir(dir)) == NULL)
                {
                        fprintf(stderr, "dirwalk: can't open %s\n", dir);
                        return;
                }

                while ((dp = readdir(dfd)) != NULL)
                {
                        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
                                continue;

                        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))
                        {
                                fprintf(stderr, "dirwalk: name too long\n");
                        }
                        else
                        {
                                sprintf(name, "%s/%s", dir, dp->d_name);
                                (*fcn)(name);
                        }
                }

                closedir(dfd);
        }
