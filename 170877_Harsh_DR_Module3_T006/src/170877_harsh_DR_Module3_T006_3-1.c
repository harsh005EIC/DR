/*
* File Name     : 170904_harsh_DR_module2_T006_3-1.c
* Description   : Our binary search makes two tests inside the loop, when one would suffice (at the price of more
		  tests outside.) Write a version with only one test inside the loop and measure the difference in run-time
* Author        : harsh_kerai
* Created       : 24-02-2026
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"header.h"
#include<stdbool.h>

void binary_search(void){

	 char repeat;
do{
	int8_t number;
	printf("Enter a number of elements you want to add in array : ");

	scanf("%hhd",&number);
	int8_t *arr=(int8_t *)malloc(number * sizeof(int8_t));

	for(int8_t index = 0; index<number; index++){
	scanf("%hhd",&arr[index]);
	}

	char confirm = 'n';

	for(int8_t index = 0; index<number-1; index++){
		if(arr[index]>arr[index+1])
		{
		  printf("Array is not sorted.(Programmer can sort array in code and search for element).\n");
		  printf("Do you want to sort the array?(y/n)\n");

		  scanf(" %c",&confirm);
		   if(confirm == 'y')
                   break;

		    else{
                        printf("The user doesn't want to sort the array.\n");
                        return;
                	}
		   break;
		}
	}

	int8_t temp;
	if(confirm == 'y'){
		for(int8_t i=0; i<number; i++){
			for(int8_t j=i+1; j<number; j++){
					if(arr[i]>arr[j])
					{
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
					}

			}
		}
	}

	for(int8_t index=0; index<number; index++)
	{
	 printf("%hhd ",arr[index]);
	}
	printf("\n");

	int8_t find;
	printf("which number you want to find : ");
	scanf("%hhd",&find);

	int8_t low=0;
	int8_t high=number-1;
	int8_t found=0;

	while(low<=high){
		int8_t mid=low + (high - low) / 2;

		if(find < arr[mid]){
		high=mid-1;
		}
		else if(find > arr[mid])
		{
		low=mid+1;
		}
		else
		{
		 printf("number %d found at positiion %d \n",find,mid);
		 found=1;
		 break;
		}
	}

	 if(!found)
         printf("Number not found\n");

	 free(arr);

	printf("\nDo you want to search again? (y/n): ");
	scanf(" %c", &repeat);
}while(repeat == 'y' || repeat == 'Y');

printf("Exiting...\n");

}

