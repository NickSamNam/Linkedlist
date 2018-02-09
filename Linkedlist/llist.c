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
	Node* curr = llist;
	while (curr->next != NULL)
	{
		curr = (curr->next);
	}
	curr->next = node;
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
		Node* curr = llist;
		int i;
		for (i = 0; i < index - 1; i++) {
			curr = (curr->next);
		}
		node->data = data;
		node->next = curr->next;
		curr->next = node;
	}
}

void llist_print(Node* llist, printer printer)
{
	Node* curr = llist;
	printf("{");
	while (curr != NULL) {
		printer(curr->data);
		curr = curr->next;
		if (curr != NULL) printf(", ");
	}
	printf("}");
}