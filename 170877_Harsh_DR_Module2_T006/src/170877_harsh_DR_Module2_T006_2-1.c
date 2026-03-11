/*
* File Name     : 170904_harsh_DR_module2_T006_2-1.c
* Description   : Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned,
                  by printing appropriate values from standard headers and by direct computation. Harder if you compute them:
		  determine the ranges of the various floating-point types.
* Author        : harsh_kerai
* Created       : 16-02-2026
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "header.h"
#include <math.h>
void range_of_datatype(void)
{
	printf("CHARACTER TYPES\n");
	printf("signed char   : %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("unsigned char : 0 to %u\n", UCHAR_MAX);
	printf("plain char    : %d to %d\n", CHAR_MIN, CHAR_MAX);

	printf("\nSHORT TYPES\n");
	printf("signed short   : %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short : 0 to %u\n", USHRT_MAX);

	printf("\nINT TYPES\n");
	printf("signed int   : %d to %d\n", INT_MIN, INT_MAX);
	printf("unsigned int : 0 to %u\n", UINT_MAX);

	printf("\nLONG TYPES\n");
	printf("signed long   : %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long : 0 to %lu\n", ULONG_MAX);

	printf("\nFLOATING POINT TYPES\n");
	printf("float       : %e to %e\n", FLT_MIN, FLT_MAX);
	printf("double      : %e to %e\n", DBL_MIN, DBL_MAX);
	printf("long double : %Le to %Le\n", LDBL_MIN, LDBL_MAX);

	 printf("\nRanges by Direct Computation\n\n");

    int bits = sizeof(char) * 8;

    printf("Signed char   : %d to %d\n",
           -(int)pow(2, bits-1),
           (int)pow(2, bits-1) - 1);

    printf("Unsigned char : 0 to %u\n",
           (unsigned int)pow(2, bits) - 1);

    bits = sizeof(int) * 8;

    printf("\nSigned int   : %d to %d\n",
           -(int)pow(2, bits-1),
           (int)pow(2, bits-1) - 1);

    printf("Unsigned int : 0 to %u\n",
           (unsigned int)pow(2, bits) - 1);

    bits = sizeof(long) * 8;

    printf("\nSigned long   : %ld to %ld\n",
           -(long)pow(2, bits-1),
           (long)pow(2, bits-1) - 1);

    printf("Unsigned long : 0 to %lu\n",
           (unsigned long)pow(2, bits) - 1);

}
