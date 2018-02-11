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

	Node* llist3 = llist_create();
	for (i = 10; i > 0; i--)
	{
		int* data = malloc(sizeof(int));
		*data = i;
		llist_add(llist3, data);
	}


	Node* llist4 = llist_create();
	for (i = 10; i > 0; i--)
	{
		int* data = malloc(sizeof(int));
		*data = i;
		llist_add(llist4, data);
	}

	llist_addAll_i(llist, 0, llist3);
	llist_addAll_i(llist, 5, llist4);

	llist_remove_i(llist, 0);

	llist_remove_i(llist, 1);

	llist_remove_i(llist, 48);

	llist_add_i(llist, 0, data);

	llist_remove_e(llist, data);
	llist_remove_e(llist, data);

	llist_print(llist, printInt);
}