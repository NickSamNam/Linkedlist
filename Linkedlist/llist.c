#include <stdlib.h>
#include <stdio.h>

#include "llist.h"
#include "printer.h"

Node* llist_create(int length)
{
	if (length < 1) {
		return NULL;
	}
	Node* llist = malloc(sizeof(Node));
	if (length > 1) {
		Node* curr = llist;
		int i;
		for (i = 0; i < length - 1; i++) {
			Node* node = malloc(sizeof(Node));
			curr->next = node;
			curr = curr->next;
		}
		curr->next = NULL;
	}
	return llist;
}

void llist_add(Node* llist, void* data)
{
	Node* node = malloc(sizeof(Node));
	while (llist->next != NULL)
	{
		llist = (llist->next);
	}
	llist->next = node;
	node->data = data;
	node->next = NULL;
}

void llist_add_i(Node* llist, int index, void* data) {
	if (index < 0) return;
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
		for (i = 0; i < index - 1; i++) {
			llist = (llist->next);
		}
		node->data = data;
		node->next = llist->next;
		llist->next = node;
	}
}

void llist_print(Node* llist, printer printer)
{
	printf("{");
	while (llist != NULL) {
		printer(llist->data);
		llist = llist->next;
		if (llist != NULL) printf(", ");
	}
	printf("}");
}