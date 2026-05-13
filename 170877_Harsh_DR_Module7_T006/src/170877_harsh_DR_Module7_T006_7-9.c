/*
* File Name     : 170877_harsh_DR_module7_T006_7-9.c
* Description   : Functions like isupper can be implemented to save space or to save time. Explore both possibilities.
* Author        : harsh_kerai
* Date          : 23/04/2025
*/


#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include <time.h>
#include <ctype.h>

int16_t isupper_space(int16_t c) {
    return (c >= 'A' && c <= 'Z');
}

unsigned char table[256] = {0};

void init_table() {
    for (int8_t i = 'A'; i <= 'Z'; i++)
        table[i] = 1;
}

int8_t isupper_time(int8_t c) {
    return table[(unsigned char)c];
}

void test(long iterations) {
    clock_t start, end;
    double time_space, time_time,time_inbuilt;
    char ch = 'G';

    start = clock();
    for (long i = 0; i < iterations; i++) {
        isupper_space(ch);
    }
    end = clock();
    time_space = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    for (long i = 0; i < iterations; i++) {
        isupper_time(ch);
    }
    end = clock();
    time_time = (double)(end - start) / CLOCKS_PER_SEC;


	start=clock();
	for(long i=0;i<iterations;i++)
	{
		isupper(ch);
	}
	end=clock();
	time_inbuilt=(double)(end-start)/ CLOCKS_PER_SEC;

    printf("Check for %ld iteration\t\nDifference of execution time = %f sec\nDifference of execution between inbuilt function and user_define function = %f\n\n\n",
           iterations, time_space - time_time, time_time - time_inbuilt);
}

void time_space() {
    init_table();

    test(100000);
    test(1000000);
    test(2000000);

    return;
}

