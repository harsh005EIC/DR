/*
* File Name     : 170877_harsh_DR_module6_T006_6-2.c
* Description   : Write a program that reads a C program and prints in alphabetical order each group of variable names that are identical in the first 6 characters, but different somewhere thereafter. Don't count words within strings and comments.
 		  Make 6 parameters that can be set from the command line.
* Author        : harsh_kerai
* Date          : 15/04/2025
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

	struct tnode{
		char *word;
		int count;
		struct tnode *left;
		struct tnode *right;
	};

	int n;

	struct tnode *addtree(struct tnode *, char *);
	void treeprint(struct tnode *);
	void groupprint(struct tnode *,struct tnode *);
	int getword(char *, int);

	struct tnode *talloc(void)
	{
		return(struct tnode *) malloc(sizeof(struct tnode));
	}

	char *strdup2(char *s)
	{
		char *p = (char *) malloc(strlen(s) + 1);
		if(p != NULL)
			strcpy(p, s);
		return p;
	}

/*
* File Name     : 170877_harsh_DR_module6_T006_6-2.c
* Description   : add a node
* Author        : harsh_kerai
* Date          : 15/04/2025
*/
	struct tnode *addtree(struct tnode *p, char *w)
	{
		int cond;

		if(p == NULL)
		{
			p = talloc();
			p->word = strdup2(w);
			p->count = 1;
			p->left = p->right = NULL;
		}
		else if((cond = strcmp(w, p->word)) == 0)
			p->count++;
		else if(cond < 0)
			p->left = addtree(p->left, w);
		else
			p->right = addtree(p->right, w);

		return p;
	}

/*
* File Name     : 170877_harsh_DR_module6_T006_6-2.c
* Description   : print words with frequency
* Author        : harsh_kerai
* Date          : 15/04/2025
*/

	void treeprint(struct tnode *p)
	{
		if(p != NULL)
		{
			treeprint(p->left);
			printf("%4d %s\n", p->count, p->word);
			treeprint(p->right);
		}
	}

/*
* File Name     : 170877_harsh_DR_module6_T006_6-2.c
* Description   : compare first n characters
* Author        : harsh_kerai
* Date          : 15/04/2025
*/

	int prefixcmp(char *s, char *t)
	{
		return strncmp(s, t, n);
	}

/*
* Description   : print grouped words
* Author        : harsh_kerai
* Date          : 15/04/2025
*/

	void groupprint_helper(struct tnode *root, struct tnode *node, int *printed)
	{
		if(node != NULL)
		{
			groupprint_helper(root, node->left, printed);

			if(prefixcmp(root->word, node->word) == 0 && strcmp(root->word, node->word) != 0)
			{
				if(!(*printed))
				{
					printf("\n%s\n", root->word);
					printf("    %d %s\n", root->count, root->word);
					*printed = 1;
				}
				printf("    %d %s\n", node->count, node->word);
			}
			groupprint_helper(root, node->right, printed);
		}
	}


	int has_same_prefix(struct tnode *root, char *word)
	{
		if(root == NULL)
			return 0;

		int cmp = strcmp(root->word, word);

		if(cmp >= 0)
			return has_same_prefix(root->left, word);

		if(prefixcmp(root->word, word) == 0)
			return 1;

		return has_same_prefix(root->left, word) || has_same_prefix(root->right, word);
	}

	void groupprint(struct tnode *root, struct tnode *whole) {
		if (root != NULL)
		{
        		groupprint(root->left, whole);

			int printed = 0;
			if(!has_same_prefix(whole, root->word))
			{
				groupprint_helper(root, whole, &printed);
			}
			groupprint(root->right, whole);
    		}
	}

/*
* Description   : get next word (ignores comments & strings)
* Author        : harsh_kerai
* Date          : 15/04/2025
*/

	int getword(char *word, int lim)
	{
		int c;
		char *w = word;

		while(isspace(c = getchar()));

 		if(c == '"')
		{
			while((c = getchar()) != '"' && c != EOF);
		return getword(word, lim);
		}

		if(c == '/')
		{
			int d = getchar();
			if(d == '/')
			{
				while((c = getchar()) != '\n' && c != EOF);
			return getword(word, lim);
			}

			else if (d == '*')
			{
				while((c = getchar()) != EOF)
				{
					if(c == '*' && (c = getchar()) == '/')
					break;
				}
			return getword(word, lim);
			}
			else
			{
				ungetc(d, stdin);
			}
		}

		if(c == '#')
		{
			while((c = getchar()) != '\n' && c != EOF);
		return getword(word, lim);
		}

		if(!isalpha(c) && c != '_')
		{
			*w = '\0';
			return c;
		}

		*w++ = c;
		while(--lim > 0)
		{
			c = getchar();
			if(!isalnum(c) && c != '_')
			{
				ungetc(c, stdin);
			break;
			}
			*w++ = c;
		}
		*w = '\0';
		return word[0];
	}

	void variable_names(int argc, char *argv[])
	{
		struct tnode *root = NULL;
		char word[MAXWORD];

		if(argc != 2)
		{
			printf("Usage: %s n\n", argv[0]);
			return;
		}

		n = atoi(argv[1]);

		while(getword(word, MAXWORD) != EOF)
		{
			if(isalpha(word[0]) || word[0] == '_')
				root = addtree(root, word);
		}

		printf("\n--- Word Frequencies ---\n");
		treeprint(root);

		printf("\n--- Groups (first %d characters same) ---\n", n);
		groupprint(root,root);

	return;
	}
