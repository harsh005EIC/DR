/*
* File Name     : 170877_harsh_DR_module5_T006_5-17.c
* Description   : Add a field-searching capability, so sorting may bee done on fields within lines, each field sorted according
		  to an independent set of options. (The index for this book was sorted with -df for the index category and -n
		  for the page numbers.)
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

	void get_fields(char *line, char **f1, char **f2)
	{
		*f1 = strtok(line, ",");
		*f2 = strtok(NULL, ",");

		if(*f2){
			while(**f2 == ' ') (*f2)++;
		}
	}

	int cmp_page(const char *s1, const char *s2)
	{
		double v1 = atof(s1);
		double v2 = atof(s2);

		if(v1 < v2)
			return -1;
		else if (v1 > v2)
			return 1;
		else
			return 0;
	}

	int isdirchar(int c)
	{
		return isalnum((unsigned char)c) || c == ' ';
	}

	int cmp_category(const char *s1, const char *s2)
	{
		char c1, c2;

	while(1){
		while(*s1 && !isdirchar(*s1)) s1++;
		while(*s2 && !isdirchar(*s2)) s2++;

		c1 = tolower((unsigned char)*s1);
		c2 = tolower((unsigned char)*s2);

		if(c1 == c2){
			if(c1 == '\0')
				return 0;
		s1++;
		s2++;
		}
		else{
			return c1 - c2;
		}
	}
	}


	int compare_lines(char *l1, char *l2)
	{
		char temp1[MAXLEN], temp2[MAXLEN];
		char *f1_1, *f1_2;
		char *f2_1, *f2_2;

		strcpy(temp1, l1);
		strcpy(temp2, l2);

		get_fields(temp1, &f1_1, &f2_1);
		get_fields(temp2, &f1_2, &f2_2);

		int result = cmp_category(f1_1, f1_2);

		if(result != 0)
		return result;

		return cmp_page(f2_1, f2_2);
	}


        void qsort_custom(char *v[], int16_t left, int16_t right)
        {
                int16_t i, last;

                if(left >= right)
                        return;

                swap(v, left, (left + right) / 2);
                last = left;

                for(i = left + 1; i <= right; i++){
			if (compare_lines(v[i], v[left]) < 0)
            			swap(v, ++last, i);
                }

                swap(v, left, last);
                qsort_custom(v, left, last - 1);
                qsort_custom(v, last + 1, right);
        }


        void sorting_field(int16_t argc, char *argv[])
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
