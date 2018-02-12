#include <stdlib.h>
#include <stdio.h>

#include "llist.h"

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
	if (*llist == NULL)
	{
		*llist = other;
	}
	else
	{
		Node* curr = *llist;
		while (curr->next != NULL)
		{
			curr = (curr->next);
		}
		curr->next = other;
	}
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

void llist_clear(Node** llist)
{
	Node* curr = *llist;
	while (curr != NULL)
	{
		Node* del = curr;
		curr = curr->next;
		free(del);
	}
	*llist = NULL;
}

int llist_length(Node* llist)
{
	int i = 0;
	while (llist != NULL)
	{
		i++;
		llist = llist->next;
	}
	return i;
}

int llist_exist(Node* llist, void* data)
{
	while (llist != NULL)
	{
		if (llist->data == data)
		{
			return 1;
		}
		llist = llist->next;
	}
	return 0;
}

Node** llist_copy_deep(Node* llist, copier copier)
{
	Node** copy = calloc(1, sizeof(Node*));
	if (llist == NULL) return copy;

	Node* curr = calloc(1, sizeof(Node));
	*copy = curr;
	while (llist != NULL)
	{
		curr->data = copier(llist->data);
		if (llist->next == NULL)
		{
			curr->next = NULL;
			break;
		}
		else
		{
			curr->next = malloc(sizeof(Node*));
		}
		curr = curr->next;
		llist = llist->next;
	}
	return copy;
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