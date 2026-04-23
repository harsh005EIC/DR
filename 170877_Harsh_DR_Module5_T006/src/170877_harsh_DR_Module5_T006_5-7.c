/*
* File Name     : 170877_harsh_DR_module5_T006_5-7.c
* Description   : Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to
                  maintain storage. How much faster is the program?
* Author        : harsh_kerai
* Date          : 31/03/2025
*/

#include <stdio.h>
#include <string.h>
#include "header.h"
#include <stdint.h>


#define MAXLINES 5000
#define MAXLEN   1000
#define MAXSTORE 10000

	char *lineptr[MAXLINES];

	int16_t readlines(char *lineptr[], int16_t maxlines, char *linestore, int16_t maxstore);
	void writelines(char *lineptr[], int16_t nlines);
	void qsort(char *v[], int16_t left, int16_t right);
	void swap(char *v[], int16_t i, int16_t j);
	int my_getline(char *s, int lim);

	void sort_lines()
	{
	int16_t nlines;
	char linestore[MAXSTORE];

	 if((nlines = readlines(lineptr, MAXLINES, linestore, MAXSTORE)) >= 0){
	   qsort(lineptr, 0, nlines - 1);
	   writelines(lineptr, nlines);
	 }

	 else{
         printf("error: input too big to sort\n");
	 }

	return;
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

	void qsort(char *v[], int16_t left, int16_t right)
	{
	int16_t i, last;

	if(left >= right)
	 return;

	swap(v, left, (left + right) / 2);
	last = left;

	for(i = left + 1; i <= right; i++)
	 if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);

	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

	void swap(char *v[], int16_t i, int16_t j)
	{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

