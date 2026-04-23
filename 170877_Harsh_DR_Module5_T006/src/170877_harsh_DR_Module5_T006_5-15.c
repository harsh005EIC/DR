/*
* File Name     : 170877_harsh_DR_module5_T006_5-15.c
* Description   : Add the option -f to fold upper and lower case together, so that case distinctions are not made during sorting;
		  for example, a and A compare equal.
* Author        : harsh_kerai
* Date          : 08/04/2025
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#define MAXLINES 5000
#define MAXLEN   1000
#define MAXSTORE 10000

        char *lineptr[MAXLINES];

        int16_t reverse = 0;
        int16_t numeric = 0;
	int16_t fold = 0;

        int16_t my_getline(char *s, int16_t lim)
        {
                int16_t c, i;

                for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
                s[i] = c;

                if(c == '\n'){
                s[i] = c;
                i++;
                }
                s[i] = '\0';
                return i;
        }

        int16_t readlines(char *lineptr[], int16_t maxlines, char *linestore, int16_t maxstore)
        {
                int16_t len, nlines = 0;
                char line[MAXLEN];
                char *p = linestore;
                char *end = linestore + maxstore;

                while((len = my_getline(line, MAXLEN)) > 0){
                        if(nlines >= maxlines || p + len > end)
                        return -1;

                        if(line[len - 1] == '\n')
				line[len - 1] = '\0';
                        strcpy(p, line);

                        lineptr[nlines++] = p;
                        p += len;
                }
                return nlines;
        }

        void writelines(char *lineptr[], int16_t nlines)
        {
                int16_t i;
                for(i = 0; i < nlines; i++)
                        printf("%s\n", lineptr[i]);
        }

        void swap(char *v[], int16_t i, int16_t j)
        {
                char *temp;
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
        }

        int16_t numcmp(const char *s1, const char *s2)
        {
                double v1 = atof(s1);
                double v2 = atof(s2);

                if(v1 < v2) return -1;
                else if(v1 > v2) return 1;
                else return 0;
        }

	int16_t strcmp_fold(const char *s1, const char *s2)
	{
		while(tolower((unsigned char)*s1) == tolower((unsigned char)*s2)){
			if(*s1 == '\0')
			return 0;
		s1++;
		s2++;
		}
		return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
	}

        void qsort_custom(char *v[], int16_t left, int16_t right)
        {
                int16_t i, last;

                if(left >= right)
                        return;

                swap(v, left, (left + right) / 2);
                last = left;

                for(i = left + 1; i <= right; i++){

                        int16_t result;

                        if(numeric)
                                result = numcmp(v[i], v[left]);
                        else if (fold)
				result = strcmp_fold(v[i], v[left]);
			else
                                result = strcmp(v[i], v[left]);

                        if(reverse)
                                result = -result;

                        if(result < 0)
                                swap(v, ++last, i);
                }

                swap(v, left, last);
                qsort_custom(v, left, last - 1);
                qsort_custom(v, last + 1, right);
        }


        void string_fold(int16_t argc, char *argv[])
        {
                int16_t nlines;
                char linestore[MAXSTORE];

                while(--argc > 0 && (*++argv)[0] == '-'){
                        char *c = *argv + 1;
                        while (*c)
                        {
                                if(*c == 'r')
                                        reverse = 1;
                                else if (*c == 'n')
                                        numeric = 1;
				else if (*c == 'f')
					fold = 1;
                        c++;
                        }
                }

                if((nlines = readlines(lineptr, MAXLINES, linestore, MAXSTORE)) >= 0)
                {
                        qsort_custom(lineptr, 0, nlines - 1);
                        writelines(lineptr, nlines);
                }

                else{
                        printf("error: input too big to sort\n");
                }
        }
