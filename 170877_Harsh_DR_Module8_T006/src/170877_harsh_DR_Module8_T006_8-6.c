/*
* File Name     : 170877_harsh_DR_module8_T006_8-6.c
* Description   : The standard library function calloc(n,size) returns a pointer to n objects of size size, with the storage initialized to zero.
                  Write calloc,by calling malloc or by modifying it.
* Author        : harsh_kerai
* Date          : 04/05/2025
*/

#include <stdio.h>
#include <stdlib.h>

        void *my_calloc(size_t n, size_t size)
        {
                size_t total;
                unsigned char *ptr;

                if (n == 0 || size == 0)
                        return NULL;

                if (size > ((size_t)-1) / n)
                        return NULL;

                total = n * size;

                ptr = (unsigned char *)malloc(total);
                if (ptr == NULL)
                        return NULL;

                for (size_t i = 0; i < total; i++)
                        ptr[i] = 0;

                return ptr;
        }

        void print_hex(unsigned char *ptr, size_t n, size_t size)
        {
                size_t total = n * size;

                printf("Memory content (in hexadecimal):\n");

                for (size_t i = 0; i < total; i++)
                {
                        printf("%02X ", ptr[i]);

                        if ((i + 1) % size == 0)
                                printf(" ");
                }

                printf("\n");
        }

        void modified_calloc()
        {
                size_t n, size;

                printf("Enter the number of elements: ");
                scanf("%zu", &n);

                printf("Enter the size of each element (in bytes): ");
                scanf("%zu", &size);

                if (n == 0 || size == 0)
                {
                        printf("Invalid input. Please enter a positive integer.\n");
                        return;
                }

                unsigned char *ptr = (unsigned char *)my_calloc(n, size);

                if (ptr == NULL)
                {
                        printf("Memory allocation failed.\n");
                        return;
                }

                printf("Memory allocated and initialized to zero.\n");

                print_hex(ptr, n, size);

                printf("\nFreeing memory...\n");
                free(ptr);

                return;
        }
