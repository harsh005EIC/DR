/*
* File Name     : 170904_harsh_DR_module2_T006_2-2.c
* Description   : Write a loop equivalent to the for loop above without using && or ||.
* Author        : harsh_kerai
* Created       : 16-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include"header.h"

void loop_equivalent_to_for_loop(void){
int16_t c;
char s[1000]="";
int8_t i = 0;
int8_t lim;

printf("enter limit :");
scanf("%hhd",&lim);
getchar();

while (i < lim) {
    c = getchar();

    if (c == '\n')
        break;

    if (c == EOF)
        break;

    s[i] = c;
    i++;
}
 s[i] = '\0';

    printf("String entered: %s\n", s);

}
 
