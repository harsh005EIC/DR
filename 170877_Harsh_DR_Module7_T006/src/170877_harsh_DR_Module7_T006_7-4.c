/*
* File Name     : 170877_harsh_DR_module7_T006_7-4.c
* Description   : Write a private version of scanf analogous to minprintf from the previous section
* Author        : harsh_kerai
* Date          : 21/04/2025
*/


#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

	void minscanf(char *fmt, ...)
	{
		va_list ap;
		char *p;

		va_start(ap, fmt);

		for(p = fmt; *p; p++)
		{
			if(*p != '%')
			continue;
			p++;

			switch(*p)
			{
				case 'd':
				{
					int8_t *ip = va_arg(ap, int8_t *);
					scanf("%hhd", ip);
					break;
				}

				case 'u':
				{
					unsigned int *up = va_arg(ap, unsigned int *);
					scanf("%u", up);
					break;
				}

				case 'f':
				{
						float *fp = va_arg(ap, float *);
						scanf("%f", fp);
					break;
				}

				case 'l':
				{
					if(*(p + 1) == 'f')
					{
						double *dp = va_arg(ap, double *);
						scanf("%lf", dp);
						p++;
					}
					break;
				}

				case 'c':
				{
					char *cp = va_arg(ap, char *);
					scanf(" %c", cp);
					break;
				}

				case 's':
				{
					char *sp = va_arg(ap, char *);
					scanf("%s", sp);
					break;
				}

				default:
					break;
			}
		}

    		va_end(ap);
	}

	void min_scanf(void)
	{
		int8_t i;
		unsigned int u;
		float f;
		double d;
		char c;
		char str[100];

		printf("Enter integer, unsigned, float, double, char, string:\n");

		minscanf("%d %u %f %lf %c %s", &i, &u, &f, &d, &c, str);

		printf("\n--- Output ---\n");
		printf("Integer  : %d\n", i);
		printf("Unsigned : %u\n", u);
		printf("Float    : %f\n", f);
		printf("Double   : %lf\n", d);
		printf("Char     : %c\n", c);
		printf("String   : %s\n", str);

		return;
	}
