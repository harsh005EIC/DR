/*
* File Name     : 170904_harsh_DR_module1_T006_1-23.c
* Description   : Write a program to remove all comments from a C program. Don't forget to handle
		  quoted strings and character constants properly. C comments don't nest.
* Author        : harsh_kerai
* Created       : 12-02-2026
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

void remove_comments(void)
{
	FILE *fp_in, *fp_out;
	int16_t c, next;
	int8_t NORMAL =0;
	int8_t string=1;
	int8_t character=2;
	int8_t mul_comment=3;
	int8_t line_comment=4;
	int8_t state=NORMAL;

	fp_in=fopen("/home/harsh005/ip.c", "r");
	fp_out = fopen("/home/harsh005/op.c", "w");

	while ((c = fgetc(fp_in)) != EOF){

	switch (state){

	case 0:
		if (c == '"'){
                    fputc(c, fp_out);
                    state =string;
                }

                else if (c == '\'')
                {
                    fputc(c, fp_out);
                    state = character;
                }
                else if (c == '/')
                {
                    next = fgetc(fp_in);
                    if (next == '*')
                        state=mul_comment;
                    else if (next == '/')
                        state = line_comment;
                    else
                    {
                        fputc(c, fp_out);
                        fputc(next, fp_out);
                    }
                }
                else
                    fputc(c, fp_out);
                break;

            case 1:
                fputc(c, fp_out);
                if (c == '"')
                    state = NORMAL;
                break;

            case 2:
                fputc(c, fp_out);
                if (c == '\\')
                    fputc(fgetc(fp_in), fp_out);
                else if (c == '\'')
                    state = NORMAL;
                break;

            case 3:
                if (c == '*')
                {
                    next = fgetc(fp_in);
                    if (next == '/')
                        state = NORMAL;
                    else
                        ungetc(next, fp_in);
 		}
		break;

		case 4:
			if (c == '\n'){
			fputc('\n', fp_out);
			state=NORMAL;
                }
                break;
	   }
	}

	fclose(fp_in);
	fclose(fp_out);

	printf("Comments removed successfully. Output stored in op.c\n");

}
