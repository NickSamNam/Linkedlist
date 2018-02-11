#include <stdlib.h>
#include <stdio.h>

#include "llist.h"
#include "printer.h"

Node* llist_create()
{
	Node* llist = malloc(sizeof(Node));
	llist->data = NULL;
	llist->next = NULL;
	return llist;
}

Node* llist_create_l(int length)
{
	if (length < 1)
	{
		return NULL;
	}
	Node* llist = malloc(sizeof(Node));
	if (length > 1)
	{
		Node* curr = llist;
		int i;
		for (i = 0; i < length - 1; i++)
		{
			Node* node = malloc(sizeof(Node));
			curr->next = node;
			curr->data = NULL;
			curr = curr->next;
		}
		curr->next = NULL;
	}
	return llist;
}

void llist_add(Node* llist, void* data)
{
	if (llist->data == NULL)
	{
		llist->data = data;
		return;
	}
	Node* node = malloc(sizeof(Node));
	while (llist->next != NULL)
	{
		llist = (llist->next);
	}
	llist->next = node;
	node->data = data;
	node->next = NULL;
}

void llist_add_i(Node* llist, int index, void* data)
{
	Node* node = malloc(sizeof(Node));
	if (index == 0)
	{
		node->data = llist->data;
		node->next = llist->next;
		llist->next = node;
		llist->data = data;
	}
	else
	{
		int i;
		for (i = 0; i < index - 1; i++)
		{
			llist = (llist->next);
		}
		node->data = data;
		node->next = llist->next;
		llist->next = node;
	}
}

void llist_addAll(Node* llist, Node* other)
{
	while (llist->next != NULL)
	{
		llist = (llist->next);
	}
	llist->next = other;
}

void llist_addAll_i(Node* llist, int index, Node* other)
{
	if (index == 0)
	{
		Node* curr = other;
		while (curr->next != NULL)
		{
			curr = (curr->next);
		}
		curr->next = llist->next;
		llist->data = other->data;
		llist->next = other->next;
	}
	else
	{
		Node* last = other;
		while (last->next != NULL)
		{
			last = (last->next);
		}
		int i;
		for (i = 0; i < index - 1; i++)
		{
			llist = (llist->next);
		}
		last->next = llist->next;
		llist->next = other;
	}
}

void llist_remove_i(Node* llist, int index)
{
	Node* next;
	if (index == 0)
	{
		next = llist->next;
		llist->data = next->data;
		llist->next = next->next;
		free(next);
	}
	else
	{
		int i;
		for (i = 0; i < index - 1; i++)
		{
			llist = (llist->next);
		}
		next = llist->next;
		llist->next = next->next;
		free(next);
	}
}


//todo
void llist_remove_e(Node* llist, void* data)
{
	int i = 0;
	while (llist->next != NULL)
	{
		if (llist->data == data)
		{
			Node* next;
			if (i == 0)
			{
				next = llist->next;
				llist->data = next->data;
				llist->next = next->next;
				free(next);
			}
			else
			{
				next = llist->next;
				llist->next = next->next;
				free(next);
			}
			break;
		}
		llist = (llist->next);
		i++;
	}
}

void llist_print(Node* llist, printer printer)
{
	printf("{");
	while (llist != NULL)
	{
		printer(llist->data);
		llist = llist->next;
		if (llist != NULL) printf(", ");
	}
	printf("}");
}