#include <stdlib.h>
#include <stdio.h>

#include "llist.h"
#include "printer.h"

Node* llist_create(int length)
{
	Node* llist = malloc(sizeof(Node));
	Node* curr = llist;
	int i;
	for (i = 0; i < length - 1; i++) {
		Node* node = malloc(sizeof(Node));
		curr->next = node;
		curr = curr->next;
	}
	curr->next = NULL;
	return llist;
}

void llist_add(Node* llist, void* data)
{
	Node* node = malloc(sizeof(Node));;
	if (llist == NULL)
	{
		llist = node;
	}
	else
	{
		Node* prev = llist;
		while (prev->next != NULL)
		{
			prev = (prev->next);
		}
		prev->next = node;
	}
	node->data = data;
	node->next = NULL;
}

void llist_print(Node* llist, printer printer)
{
	while (llist != NULL) {
		printer(llist->data);
		llist = llist->next;
	}
}