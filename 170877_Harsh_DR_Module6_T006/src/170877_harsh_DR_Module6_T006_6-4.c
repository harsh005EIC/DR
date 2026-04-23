/*
* File Name     : 170877_harsh_DR_module6_T006_6-4.c
* Description   : Write a program that prints the distinct words in its input sorted into decreasing order of frequency of
		  occurrence. Precede each word by its count.
* Author        : harsh_kerai
* Date          : 17/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
#define MAXNODES 1000

	struct tnode *nodes[MAXNODES];
	int node_count = 0;

        struct tnode{
                char *word;
                int count;
                struct tnode *left;
                struct tnode *right;
        };

        struct tnode* talloc(char *word)
        {
                struct tnode *p = malloc(sizeof(struct tnode));
                p->word = strdup(word);
                p->count = 1;
                p->left = p->right = NULL;
        return p;
        }

        struct tnode* addtree(struct tnode *root, char *word) {
                int cond;

                if(root == NULL)
                return talloc(word);

                cond = strcmp(word, root->word);

                if(cond == 0)
                {
                        root->count++;
                }
                else if(cond < 0)
                {
                        root->left = addtree(root->left, word);
                }
                else
                {
                        root->right = addtree(root->right, word);
                }
                return root;
        }


	void collect_nodes(struct tnode *root)
	{
		if(root != NULL)
		{
			collect_nodes(root->left);
			nodes[node_count++] = root;
			collect_nodes(root->right);
		}
	}

	int cmp(const void *a, const void *b)
	{
		struct tnode *n1 = *(struct tnode **)a;
		struct tnode *n2 = *(struct tnode **)b;

		return n2->count - n1->count;
	}

        int getword(char *word)
        {
                int c;
                char *w = word;

                while((c = getchar()) != EOF)
                {
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

        void cross_reff_dec_order()
        {
                struct tnode *root = NULL;
                char word[MAXWORD];

                while(getword(word) != EOF)
                {
                                root = addtree(root, word);
                }

		collect_nodes(root);

		qsort(nodes, node_count, sizeof(struct tnode *), cmp);

		printf("\nCross Reference (Decreasing Count):\n\n");

		for(int i = 0; i < node_count; i++)
		{
			printf("%s (%d)\n", nodes[i]->word, nodes[i]->count);
		}
		return;
        }
