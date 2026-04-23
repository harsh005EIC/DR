/*
* File Name     : 170877_harsh_DR_module5_T006_5-5.c
* Description   : Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first
		  n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
		  Full descriptions are in Appendix B.
* Author        : harsh_kerai
* Date          : 31/03/2025
*/
#include <stdio.h>
#include "header.h"
#include <stdint.h>
#include <stddef.h>
#include <string.h>

void my_strncpy(char *dest,char *src,size_t n)
{
	size_t i;

	for(i = 0; i < n && src[i] != '\0'; i++)
	  dest[i] = src[i];

	for(;i < n;i++)
	  dest[i] = '\0';
}

void my_strncat(char *dest, char *src, size_t n)
{
	size_t i, j;

	for(i = 0; dest[i] != '\0'; i++);

	for(j=0; j<n && src[j] != '\0'; j++)
	dest[i + j] = src[j];

	dest[i + j] = '\0';

}

int my_strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for(i = 0;i < n; i++)
	{
	 if(s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            return (s1[i] - s2[i]);
	}

    return 0;
}

void str_functions(void){

	char s1[100], s2[100], buffer[100];
	size_t n;
	int8_t choice;

	printf("Enter first string: ");
	fgets(s1, sizeof(s1), stdin);

	printf("Enter second string: ");
	fgets(s2, sizeof(s2), stdin);

	s1[strcspn(s1,"\n")] = '\0';
	s2[strcspn(s2,"\n")] = '\0';

	printf("\nChoose operation:\n");

	printf("1.strncpy\n");
	printf("2.strncat\n");
	printf("3.strncmp\n");

	printf("Enter choice: ");
	scanf("%hhd",&choice);

	printf("Enter value of n: ");
	scanf("%zu", &n);

	switch(choice){

	case 1:
            my_strncpy(buffer, s2, n);
              if(n < sizeof(buffer))
                buffer[n] = '\0';
            printf("Result : %s\n", buffer);
            break;

        case 2:
            my_strncat(s1, s2, n);
            printf("Result : %s\n", s1);
            break;

        case 3:
        {
            int result = my_strncmp(s1, s2, n);
            if (result == 0)
                printf("First %zu characters are equal\n", n);
            else if (result < 0)
                printf("s1 is less than s2\n");
            else
                printf("s1 is greater than s2\n");
            break;
        }

        default:
            printf("Invalid choice\n");
    }

    return;
}
