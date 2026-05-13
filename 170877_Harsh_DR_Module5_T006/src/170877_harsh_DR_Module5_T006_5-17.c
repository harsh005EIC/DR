/*
* File Name     : 170877_harsh_DR_module5_T006_5-17.c
* Description   : Add a field-searching capability, so sorting may bee done on fields within lines, each field sorted according
                  to an independent set of options. (The index for this book was sorted with -df for the index category and -n
                  for the page numbers.)
* Author        : harsh_kerai
* Date          : 08/04/2025
*/

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define MAXSTORE 10000
#define MAXFIELDS 10

char *lineptr[MAXLINES];

        typedef struct
        {
                int16_t field_no;
                int16_t numeric;
                int16_t reverse;
                int16_t fold;
                int16_t directory;
        } Field;

        Field fields[MAXFIELDS];
        int nfields = 0;

        int16_t my_getline(char *s, int16_t lim)
        {
                int16_t c, i;

                for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
                        s[i] = c;

                if (c == '\n')
                        s[i++] = c;

                s[i] = '\0';
                return i;
        }

        int16_t readlines(char *lineptr[], int16_t maxlines, char *linestore, int16_t maxstore)
        {
                int16_t len, nlines = 0;
                char line[MAXLEN];
                char *p = linestore;
                char *end = linestore + maxstore;

                while ((len = my_getline(line, MAXLEN)) > 0)
                {
                        if (nlines >= maxlines || p + len > end)
                                return -1;

                        line[len - 1] = '\0';
                        strcpy(p, line);

                        lineptr[nlines++] = p;
                        p += len;
                }
                return nlines;
        }

        void writelines(char *lineptr[], int16_t nlines)
        {
                for (int i = 0; i < nlines; i++)
                        printf("%s\n", lineptr[i]);
        }

        void swap(char *v[], int16_t i, int16_t j)
        {
                char *temp = v[i];
                v[i] = v[j];
                v[j] = temp;
        }

        void get_field(const char *line, int field_no, char *buf)
        {
                int16_t i = 1;

                while (*line && i < field_no)
                {
                        if (*line == ',')
                                i++;
                        line++;
                }

                if (!*line)
                {
                        buf[0] = '\0';
                        return;
                }

                while (*line == ' ')
                        line++;

                int16_t j = 0;

                while (*line && *line != ',' && j < MAXLEN - 1)
                {
                        buf[j++] = *line++;
                }

                buf[j] = '\0';
        }

        int16_t compare_field(const char *l1, const char *l2, Field *f)
        {
                char s1[MAXLEN], s2[MAXLEN];

                get_field(l1, f->field_no, s1);
                get_field(l2, f->field_no, s2);

                int result;

                if (f->numeric)
                {
                        double v1 = atof(s1);
                        double v2 = atof(s2);
                        result = (v1 > v2) - (v1 < v2);
                }
                else
                {
                        char *p1 = s1;
                        char *p2 = s2;

                        while (1)
                        {
                                if (f->directory)
                                {
                                        while (*p1 && !isalnum(*p1) && *p1 != ' ')
                                                p1++;
                                        while (*p2 && !isalnum(*p2) && *p2 != ' ')
                                                p2++;
                                }

                                char c1 = f->fold ? tolower(*p1) : *p1;
                                char c2 = f->fold ? tolower(*p2) : *p2;

                                if (c1 != c2)
                                {
                                        result = c1 - c2;
                                        break;
                                }

                                if (c1 == '\0')
                                {
                                        result = 0;
                                        break;
                                }

                                p1++;
                                p2++;
                        }
                }

                if (f->reverse)
                        result = -result;

                return result;
        }

        int16_t compare_lines(char *l1, char *l2)
        {
                for (int8_t i = 0; i < nfields; i++)
                {
                        int16_t res = compare_field(l1, l2, &fields[i]);
                        if (res != 0)
                                return res;
                }
                return 0;
        }

        void qsort_custom(char *v[], int16_t left, int16_t right)
        {
                int16_t i, last;

                if (left >= right)
                        return;

                swap(v, left, (left + right) / 2);
                last = left;

                for (i = left + 1; i <= right; i++)
                {
                        if (compare_lines(v[i], v[left]) < 0)
                                swap(v, ++last, i);
                }

                swap(v, left, last);

                qsort_custom(v, left, last - 1);
                qsort_custom(v, last + 1, right);
        }

        void parse_args(int argc, char *argv[])
        {
                while (--argc > 0)
                {
                        char *arg = *++argv;

                        if (arg[0] == '-' && arg[1] == 'f')
                        {
                                Field f = {0, 0, 0, 0, 0};

                                f.field_no = atoi(arg + 2);

                                char *c = arg + 2;
                                while (isdigit(*c))
                                        c++;

                                for (; *c; c++)
                                {
                                        if (*c == 'n')
                                                f.numeric = 1;
                                        else if (*c == 'r')
                                                f.reverse = 1;
                                        else if (*c == 'd')
                                                f.directory = 1;
                                        else if (*c == 'f')
                                                f.fold = 1;
                                }

                                fields[nfields++] = f;
                        }
                }

                if (nfields == 0)
                {
                        fields[0].field_no = 1;
                        nfields = 1;
                }
        }

        void sorting_field(int argc, char *argv[])
        {
                int16_t nlines;
                char linestore[MAXSTORE];

                parse_args(argc, argv);

                if ((nlines = readlines(lineptr, MAXLINES, linestore, MAXSTORE)) >= 0)
                {
                        qsort_custom(lineptr, 0, nlines - 1);
                        writelines(lineptr, nlines);
                }
                else
                {
                        printf("error: input too big to sort\n");
                }

                return;
        }
