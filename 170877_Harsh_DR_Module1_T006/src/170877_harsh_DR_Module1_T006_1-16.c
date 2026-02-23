/*
* File Name     : 170904_harsh_DR_module1_T006_1-1.c
* Description   : Revise the main routine of the longest-line program so it will correctly
		  print the length of arbitrary long input lines, and as much as possible of the text.
* Author        : harsh_kerai
* Created       : 10-02-2026
*/
#include<stdio.h>
#include<stdint.h>
#include "header.h"
#include <string.h>

#define MAXLINE 1000

void longest_line(void)
{
char line[MAXLINE];
char longest[MAXLINE] = "";
int32_t max_len = 0;

	while (fgets(line, sizeof(line), stdin) != NULL) {
		int32_t len = strlen(line);

	if (line[len - 1] == '\n') {
		line[--len] = '\0';
	}

	while (len > 0 && line[len - 1] == ' ') {
		line[--len] = '\0';
	}

	if (len > max_len) {
		max_len = len;
		strcpy(longest, line);
	  }
	}

	if (max_len > 0) {
	printf("Longest line is %s with length %d \n", longest,max_len);
	}

}

