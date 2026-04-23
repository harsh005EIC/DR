/*
* File Name     : 170877_harsh_DR_module5_T006_5-6.c
* Description   : Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. Good
                  possibilities include getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4),
                  reverse (Chapter 3), and strindex and getop (Chapter 4).
* Author        : harsh_kerai
* Date          : 31/03/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

#define MAXLINE 1000
#define NUMBER '0'

	int16_t my_getline(char *s, int16_t lim);
	int16_t my_atoi(const char *s, int16_t *result);
	void my_itoa(int16_t n, char *s);
	void reverse(char *s);
	int16_t strindex(const char *s, const char *t);
	int16_t my_getop(char *s);

	char input[MAXLINE];
	int16_t pos = 0;

void my_function()
{
	int8_t choice;
	char s[MAXLINE], t[MAXLINE];
	int16_t num;

        printf("1. getline\n");
        printf("2. atoi\n");
        printf("3. itoa\n");
        printf("4. reverse\n");
        printf("5. strindex\n");
        printf("6. getop (parse input)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%hhd", &choice);
        getchar();

	switch(choice){
	case 1:
	    printf("Enter a line: ");
            my_getline(s, MAXLINE);
	    printf("You entered: %s\n", s);
            break;

	case 2:
	    printf("Enter a number string: ");
	    my_getline(s, MAXLINE);

	    if(my_atoi(s, &num)){
	      printf("Integer: %d\n", num);
	    }

	    else{
	      printf("Invalid input!\n");
	    }
	break;

	case 3:
	     printf("Enter integer: ");

	     if(scanf("%hd", &num) != 1){
	       printf("Invalid input!\n");

	     while(getchar() != '\n');

             break;
	     }

	    getchar();

	    my_itoa(num, s);
	    printf("String: %s\n", s);
	break;

	case 4:
		printf("Enter string: ");
		my_getline(s, MAXLINE);
		reverse(s);
		printf("Reversed: %s\n", s);
	break;

        case 5:
	    printf("Enter main string: ");
	    my_getline(s, MAXLINE);
	    printf("Enter substring: ");
	    my_getline(t, MAXLINE);

	    s[strcspn(s,"\n")] = '\0';
            t[strcspn(t,"\n")] = '\0';

	    int posi = strindex(s, t);
	    if(posi >= 0)
		printf("Found at index: %d\n", posi);
	    else
		printf("Not found\n");
	break;

	case 6:
	    my_getop(s);
	break;

        case 7:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice\n");
        }

    return;
}
