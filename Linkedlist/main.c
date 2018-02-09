#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include "printer.h"

void main()
{
	Node* llist = llist_create_l(10);

	int i;
	Node* curr = llist;
	for (i = 0; i < 10; i++) {
		int* data = malloc(sizeof(int));
		*data = i;
		curr->data = data;
		curr = curr->next;
	}
	for (i = 0; i < 10; i++) {
		int* data = malloc(sizeof(int));
		*data = i;
		llist_add(llist, data);
	}

	int* data = malloc(sizeof(int));
	*data = 999;
	llist_add_i(llist, 0, data);
	llist_add_i(llist, 11, data);

	Node* llist2 = llist_create();
	for (i = 10; i > 0; i--)
	{
		int* data = malloc(sizeof(int));
		*data = i;
		llist_add(llist2, data);
	}

	llist_addAll(llist, llist2);

	llist_print(llist, printInt);
}