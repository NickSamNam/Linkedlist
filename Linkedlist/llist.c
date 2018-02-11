#include <stdlib.h>
#include <stdio.h>

#include "llist.h"
#include "printer.h"

Node** llist_create()
{
	Node** llist = calloc(1, sizeof(Node*));
	return llist;
}

Node** llist_create_l(int length)
{
	Node** llist = calloc(1, sizeof(Node*));
	if (length > 0)
	{
		*llist = calloc(1, sizeof(Node));
	}
	if (length > 1)
	{
		Node* curr = *llist;
		int i;
		for (i = 0; i < length - 1; i++)
		{
			Node* node = calloc(1, sizeof(Node));
			curr->next = node;
			curr = curr->next;
		}
	}
	return llist;
}

void llist_add(Node** llist, void* data)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (*llist == NULL)
	{
		*llist = node;
	}
	else
	{
		Node* curr = *llist;
		while (curr->next != NULL)
		{
			curr = (curr->next);
		}
		curr->next = node;
	}
}

void llist_add_i(Node** llist, int index, void* data)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	if (index == 0)
	{
		node->next = *llist;
		*llist = node;
	}
	else
	{
		Node* curr = *llist;
		int i;
		for (i = 1; i < index; i++)
		{
			curr = curr->next;
		}
		node->next = curr->next;
		curr->next = node;
	}
}

void llist_addAll(Node** llist, Node* other)
{
	Node* curr = *llist;
	while (curr->next != NULL)
	{
		curr = (curr->next);
	}
	curr->next = other;
}

void llist_addAll_i(Node** llist, int index, Node* other)
{
	if (index == 0)
	{
		Node* curr = other;
		while (curr->next != NULL)
		{
			curr = (curr->next);
		}
		curr->next = *llist;
		*llist = other;
	}
	else
	{
		Node* curr = *llist;
		Node* last = other;
		while (last->next != NULL)
		{
			last = (last->next);
		}
		int i;
		for (i = 0; i < index - 1; i++)
		{
			curr = curr->next;
		}
		last->next = curr->next;
		curr->next = other;
	}
}

void llist_remove_i(Node** llist, int index)
{
	Node* next;
	if (index == 0)
	{
		next = (*llist)->next;
		free(*llist);
		*llist = next;
	}
	else
	{
		Node* curr = *llist;
		int i;
		for (i = 0; i < index - 1; i++)
		{
			curr = curr->next;
		}
		next = curr->next;
		curr->next = next->next;
		free(next);
	}
}

void llist_remove_e(Node** llist, void* data)
{
	Node* next;
	if ((*llist)->data == data)
	{
		next = (*llist)->next;
		free(*llist);
		*llist = next;
	}
	else
	{
		Node* curr = *llist;
		while (curr->next != NULL)
		{
			if (curr->next->data == data)
			{
				next = curr->next;
				curr->next = next->next;
				free(next);
				break;
			}
			curr = (curr->next);
		}
	}
}

void llist_print(Node* llist, printer printer)
{
	printf("{");
	while (llist != NULL)
	{
		if (llist->data == NULL)
		{
			printf("NULL");
		}
		else
		{
			printer(llist->data);
		}
		llist = llist->next;
		if (llist != NULL) printf(", ");
	}
	printf("}");
}