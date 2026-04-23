/*
* File Name     : 170877_harsh_DR_module6_T006_6-3.c
* Description   : Write a cross-referencer that prints a list of all words in a document, and for each word, a list of the
		  line numbers on which it occurs. Remove noise words like ``the,'' ``and,'' and so on.
* Author        : harsh_kerai
* Date          : 16/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

	struct lnode
	{
		int line;
		struct lnode *next;
	};

	struct tnode{
		char *word;
		int count;
		struct lnode *lines;
		struct tnode *left;
		struct tnode *right;
	};

	char *noise[] = {
		"a", "an", "the", "is", "are", "was", "were",
		"to", "of", "and","i", "in", "on", "for", "with",
		"at", "by", "from", "as", "it", "this", "that","am"
	};

	int noise_count = sizeof(noise) / sizeof(noise[0]);

	int is_noise(char *word)
	{
		for(int i = 0; i < noise_count; i++)
		{
			if(strcmp(word, noise[i]) == 0)
			return 1;
		}
		return 0;
	}

	struct lnode* addline(struct lnode *head, int line)
	{
		struct lnode *temp = head;

		while(temp)
		{
			if(temp->line == line)
			return head;
			if(temp->next == NULL)
			break;
			temp = temp->next;
		}

		struct lnode *newnode = malloc(sizeof(struct lnode));
		newnode->line = line;
		newnode->next = NULL;

		if(head == NULL)
		return newnode;

		temp->next = newnode;
		return head;
	}

	struct tnode* talloc(char *word, int line)
	{
		struct tnode *p = malloc(sizeof(struct tnode));
		p->word = strdup(word);
		p->count = 1;
		p->lines = NULL;
		p->lines = addline(p->lines, line);
		p->left = p->right = NULL;
	return p;
	}

	struct tnode* addtree(struct tnode *root, char *word, int line) {
		int cond;

		if(root == NULL)
		return talloc(word, line);

		cond = strcmp(word, root->word);

		if(cond == 0)
		{
			root->count++;
			root->lines = addline(root->lines, line);
		}
		else if(cond < 0)
		{
			root->left = addtree(root->left, word, line);
		}
		else
		{
			root->right = addtree(root->right, word, line);
		}
		return root;
	}

	void treeprint(struct tnode *root)
	{
		if(root != NULL)
		{
			treeprint(root->left);
			printf("%s (%d): ", root->word, root->count);

			struct lnode *temp = root->lines;
			while(temp)
			{
				printf("%d ", temp->line);
				temp = temp->next;
			}
				printf("\n");

			treeprint(root->right);
		}
	}

	int getword(char *word, int *line)
	{
		int c;
		char *w = word;

		while((c = getchar()) != EOF)
		{
			if(c == '\n')
				(*line)++;

			if(isalpha(c))
			{
				*w++ = tolower(c);
				break;
			}
		}

		if(c == EOF)
			return EOF;

		while((c = getchar()) != EOF && isalnum(c))
		{
			*w++ = tolower(c);
		}

		*w = '\0';
		return word[0];
	}

	void cross_reff()
	{
		struct tnode *root = NULL;
		char word[MAXWORD];
		int line = 1;

		while(getword(word, &line) != EOF)
		{
			if(!is_noise(word))
			{
				root = addtree(root, word, line);
			}
		}

		printf("\nCross Reference:\n\n");
		treeprint(root);

		return;
	}
