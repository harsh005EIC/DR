/*
* File Name     : 170877_harsh_DR_module6_T006_6-5.c
* Description   : Write a function undef that will remove a name and definition from the table maintained by lookup and install.
* Author        : harsh_kerai
* Date          : 20/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101
#define MAXLINE 1000

	struct nlist {
		char *name;
		char *defn;
		struct nlist *next;
	};

	struct nlist *hashtab[HASHSIZE];

	unsigned hash(char *s);
	struct nlist *lookup(char *s);
	struct nlist *install(char *name, char *defn);
	void undef(char *name);
	char *my_strdup(char *s);
	void print_table();

	unsigned hash(char *s)
	{
		unsigned hashval = 0;
		while(*s)
		hashval=*s++ + 31 * hashval;

		return hashval % HASHSIZE;
	}

	struct nlist *lookup(char *s)
	{
		struct nlist *np;
		for(np = hashtab[hash(s)]; np != NULL; np = np->next)
			if(strcmp(s, np->name) == 0)
			return np;
		return NULL;
	}

	char *my_strdup(char *s)
	{
		char *p = malloc(strlen(s) + 1);
		if(p)
		strcpy(p, s);

		return p;
	}

	struct nlist *install(char *name, char *defn)
	{
		struct nlist *np;
		unsigned hashval;

		if((np = lookup(name)) == NULL)
		{
			np=malloc(sizeof(*np));
			if(np == NULL || (np->name = my_strdup(name)) == NULL)
				return NULL;

			hashval = hash(name);
			np->next = hashtab[hashval];
			hashtab[hashval] = np;
		}
		else
		{
			free(np->defn);
		}

		if((np->defn = my_strdup(defn)) == NULL)
			return NULL;

		return np;
	}

	void undef(char *name)
	{
		unsigned hashval = hash(name);
		struct nlist *curr = hashtab[hashval];
		struct nlist *prev = NULL;

		while(curr)
		{
			if(strcmp(name, curr->name) == 0)
			{
				if(prev == NULL)
					hashtab[hashval] = curr->next;
				else
					prev->next = curr->next;

				free(curr->name);
				free(curr->defn);
				free(curr);

				printf("\nEntry '%s' removed successfully.\n", name);
				return;
			}
			prev = curr;
			curr = curr->next;
		}

		printf("\nEntry '%s' not found.\n", name);
	}

	void print_table()
	{
		struct nlist *np;
		int i;

		printf("\nCurrent Hash Table:\n");
		for(i = 0; i < HASHSIZE; i++)
		{
			for(np = hashtab[i]; np != NULL; np = np->next)
			{
				printf("%-15s : %s\n", np->name, np->defn);
			}
		}
	}

	void un_def()
	{
		char name[MAXLINE], defn[MAXLINE];
		int n, i;

		printf("Enter number of entries: ");
		scanf("%d", &n);
		getchar();

		for(i = 0; i < n; i++)
		{
			printf("\nEnter Name: ");
			fgets(name, MAXLINE, stdin);
			name[strcspn(name, "\n")] = '\0';

			printf("Enter Definition: ");
			fgets(defn, MAXLINE, stdin);
			defn[strcspn(defn, "\n")] = '\0';

			install(name, defn);
		}

		print_table();

		printf("\nEnter key to remove: ");
		fgets(name, MAXLINE, stdin);
		name[strcspn(name, "\n")] = '\0';

		undef(name);

		print_table();

		return;
	}
