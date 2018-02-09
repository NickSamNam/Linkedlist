#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include "printer.h"

void main()
{
	Node* llist = llist_create(10);

	int i;
	Node* curr = llist;
	for (i = 0; i < 10; i++) {
		int* data = malloc(sizeof(int));
		*data = i;
		curr->data = data;
		curr = curr->next;
	}

	int* data = malloc(sizeof(int));
	*data = 10;
	llist_add(llist, data);

	llist_print(llist, printInt);
}