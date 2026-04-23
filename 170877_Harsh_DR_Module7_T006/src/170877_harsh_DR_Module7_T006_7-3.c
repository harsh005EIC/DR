/*
* File Name     : 170877_harsh_DR_module7_T006_7-3.c
* Description   : Revise minprintf to handle more of the other facilities of printf
* Author        : harsh_kerai
* Date          : 21/04/2025
*/

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

	void minprintf(char *fmt, ...)
	{
		va_list ap;
		char *p, *sval;
		int8_t ival;
		unsigned int uval;
		double dval;
		void *ptr;

		va_start(ap, fmt);

		for(p = fmt; *p; p++)
		{
			if(*p != '%')
			{
				putchar(*p);
				continue;
			}

			switch(*++p)
			{
				case 'd':
					ival = va_arg(ap, int);
					printf("%d", ival);
					break;

				case 'u':
					uval = va_arg(ap, unsigned int);
					printf("%u", uval);
					break;

				case 'f':
					dval = va_arg(ap, double);
					printf("%f", dval);
					break;

				case 'c':
					ival = va_arg(ap, int);
					putchar(ival);
					break;

				case 's':
					sval = va_arg(ap, char *);
					printf("%s", sval);
					break;

				case 'o':
					uval = va_arg(ap, unsigned int);
					printf("%o", uval);
					break;

				case 'x':
					uval = va_arg(ap, unsigned int);
					printf("%x", uval);
					break;

				case 'p':
					ptr = va_arg(ap, void *);
					printf("%p", ptr);
					break;

				case '%':
					putchar('%');
					break;

				default:
					putchar('%');
					putchar(*p);
					break;
			}
		}
		va_end(ap);
	}

	void min_printf(void)
	{
		int8_t i;
		unsigned int u;
		float f;
		double d;
		char c;
		char str[100];

		printf("Enter integer: ");
			scanf("%hhd", &i);

		printf("Enter unsigned integer: ");
			scanf("%u", &u);

		printf("Enter float: ");
			scanf("%f", &f);

		printf("Enter double: ");
			scanf("%lf", &d);

		printf("Enter character: ");
			scanf(" %c", &c);

		printf("Enter string: ");
			getchar();
			fgets(str, sizeof(str), stdin);
			str[strcspn(str, "\n")] = '\0';

		printf("\n--- Output using minprintf ---\n");

		minprintf("Integer: %d\n", i);
		minprintf("Unsigned: %u\n", u);
		minprintf("Float: %f\n", f);
		minprintf("Double: %f\n", d);
		minprintf("Character: %c\n", c);
		minprintf("String: %s\n", str);
		minprintf("Octal: %o\n", i);
		minprintf("Hexadecimal: %x\n", i);
		minprintf("Pointer pPointer: %p",&i);
		return;
	}
