/*
* File Name     : 170877_harsh_DR_module5_T006_5-9.c
* Description   : Rewrite the routines day_of_year and month_day with pointers instead of indexing.
* Author        : harsh_kerai
* Date          : 01/04/2025
*/

#include <stdio.h>
#include "header.h"
#include <stdint.h>

static int daytab[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int16_t day_of_year(int16_t year, int16_t month, int16_t day)
{
	int8_t i,leap;

	if(year <= 0){
	 printf("Year must be positive.\n");
	 return -1;
	}

	if(month < 1 || month > 12){
	  printf("Month must be between 1 and 12.\n");
	  return -1;
	}

	leap=(year%4 == 0 && year%100 != 0) || (year%400 == 0);

	if(day < 1 || day > daytab[leap][month]){
        printf("Invalid day for given month and year.\n");
        return -1;
	}

	int *p = *(daytab + leap);

	for(i = 1; i < month; i++)
        day += *(p+i);

    return day;
}

int16_t month_day(int16_t year, int16_t yearday, int16_t *pmonth, int16_t *pday)
{
    int16_t i, leap;

	if(year <= 0){
	  printf("Year must be positive.\n");
        return -1;
	}

	leap=(year%4 == 0 && year%100 != 0) || (year%400 == 0);

	int16_t max_days = leap ? 366 : 365;

	if(yearday < 1 || yearday > max_days) {
	printf("Error: Day of the year must be between 1 and %hd.\n", max_days);
        return -1;
	}

	int *p = *(daytab + leap);

	for(i = 1; yearday > *(p + i); i++)
	yearday -= *(p + i);

	  *pmonth = i;
	  *pday = yearday;
	return 0;
}

void calender_pointer(void)
{
	int8_t choice;
	int16_t year, month, day, yearday;
	int8_t result;

	printf("Choose operation:\n");
	printf("1. Convert (year, month, day) -> day of year\n");
	printf("2. Convert (year, day of year) -> month, day\n");
	printf("Enter choice: ");
	scanf("%hhd", &choice);

	if(choice == 1){
	  printf("\nEnter year month day: ");
	  scanf("%hd %hd %hd", &year, &month, &day);

	  result=day_of_year(year,month,day);

        if(result != -1)
	  printf("%hd-%hd-%hd is %hhdth day of %hd\n",day, month, year, result, year);
        else
            printf("Invalid Entry!!!\n");
	}

	else if(choice == 2){

	printf("\nEnter year and day of year: ");
	scanf("%hd %hd", &year, &yearday);

	if(month_day(year, yearday, &month, &day) == 0)
	   printf("Month = %hd, Day = %hd\n", month, day);
	else
           printf("Invalid Entry!!!\n");
	}

	else{
	printf("Invalid choice!\n");
	}

    return;
}
