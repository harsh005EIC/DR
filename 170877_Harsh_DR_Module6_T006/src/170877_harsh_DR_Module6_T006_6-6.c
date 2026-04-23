/*
* File Name     : 170877_harsh_DR_module6_T006_6-6.c
* Description   : Implement a simple version of the #define processor (i.e., no arguments) suitable for use with C programs,
		  based on the routines of this section. You may also find getch and ungetch helpful.
* Author        : harsh_kerai
* Date          : 20/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101
#define MAXLINE 1000

	struct nlist
	{
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
	void process_line(char *line);

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
		char *p=malloc(strlen(s) + 1);
		if(p) strcpy(p, s);

		return p;
	}

	struct nlist *install(char *name, char *defn)
	{
		struct nlist *np;
		unsigned hashval;

		if((np = lookup(name)) == NULL)
		{
			np=malloc(sizeof(*np));
			if(!np || !(np->name = my_strdup(name)))
				return NULL;

			hashval = hash(name);
			np->next = hashtab[hashval];
			hashtab[hashval] = np;
		}
		else
		{
			free(np->defn);
		}

		if(!(np->defn = my_strdup(defn)))
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

            printf("Removed: %s\n", name);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Not found: %s\n", name);
}

	void process_line(char *line)
	{
		char name[MAXLINE], defn[MAXLINE];

		if(strncmp(line, "#define", 7) == 0)
		{
			if(sscanf(line + 7, "%s %s", name, defn) == 2)
			{
				install(name, defn);
			}
		}
	}

	void print_table()
	{
		struct nlist *np;
		int i;

		printf("\nHash Table:\n");
		for(i = 0; i < HASHSIZE; i++)
		{
			for(np = hashtab[i]; np != NULL; np = np->next)
			{
				printf("%-15s : %s\n", np->name, np->defn);
			}
		}
	}

	void pre_processor()
	{
		char line[MAXLINE];
		char key[MAXLINE];

		printf("Enter lines (#define NAME VALUE). Type END to stop:\n");

		while(1)
		{
			fgets(line, MAXLINE, stdin);
			if(strncmp(line, "END", 3) == 0)
			break;
			process_line(line);
		}

		print_table();

		printf("\nEnter key to remove: ");
		fgets(key,MAXLINE,stdin);
		key[strcspn(key, "\n")] = '\0';

		undef(key);

		print_table();

		return;
	}
