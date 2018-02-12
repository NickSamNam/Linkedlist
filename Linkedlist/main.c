#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

void main()
{
	/* Create llist (size = 10): llist_create_l */
	Node** llist = llist_create_l(10);

	llist_print(*llist, printInt);
	printf("\n");

	/* Fill list manually */
	int i;
	Node* curr = *llist;
	for (i = 0; i < 10; i++) {
		int* data = malloc(sizeof(int));
		*data = i;
		curr->data = data;
		curr = curr->next;
	}

	llist_print(*llist, printInt);
	printf("\n");

	/* Add item to end: llist_add */
	for (i = 0; i < 10; i++) {
		int* data = malloc(sizeof(int));
		*data = i;
		llist_add(llist, data);
	}

	llist_print(*llist, printInt);
	printf("\n");

	/* Add item at index: llist_add_i */
	int* data = malloc(sizeof(int));
	*data = 999;
	llist_add_i(llist, 0, data);
	llist_add_i(llist, 11, data);

	llist_print(*llist, printInt);
	printf("\n");

	/* Create second llist (size = 0): llist_create */
	Node** llist2 = llist_create();
	for (i = 10; i > 0; i--)
	{
		int* data = malloc(sizeof(int));
		*data = i;
		llist_add(llist2, data);
	}

	/* Add second llist to end of first llist: llist_addAll */
	llist_addAll(llist, *llist2);

	llist_print(*llist, printInt);
	printf("\n");

	/* Add list at index: llist_addAll_i */
	Node** llist3 = llist_create();
	for (i = 10; i > 0; i--)
	{
		int* data = malloc(sizeof(int));
		*data = i;
		llist_add(llist3, data);
	}


	Node** llist4 = llist_create();
	for (i = 10; i > 0; i--)
	{
		int* data = malloc(sizeof(int));
		*data = i;
		llist_add(llist4, data);
	}

	llist_addAll_i(llist, 0, *llist3);
	llist_addAll_i(llist, 11, *llist4);

	llist_print(*llist, printInt);
	printf("\n");

	/* Remove item at index: llist_remove_i */
	llist_remove_i(llist, 0);
	llist_remove_i(llist, 8);
	llist_remove_i(llist, 49);

	llist_print(*llist, printInt);
	printf("\n");

	/* Remove item contain element: llist_remove_e */
	llist_add_i(llist, 0, data);
	llist_remove_e(llist, data);
	llist_remove_e(llist, data);

	llist_print(*llist, printInt);
	printf("\n");

	/* Clear list: llist_clear */
	llist_clear(llist);

	llist_print(*llist, printInt);
	printf("\n");

	Node** llist5 = llist_create();
	for (i = 10; i > 0; i--)
	{
		int* data = malloc(sizeof(int));
		*data = i;
		llist_add(llist5, data);
	}
	llist_addAll(llist, *llist5);

	llist_print(*llist, printInt);
	printf("\n");

	/* Number of items: llist_length */
	printf("Number of items: %d\n", llist_length(*llist));

	/* Item exists: llist_exist */
	printf("%d exists: %d\n", *((int*)((*llist)->data)), llist_exist(*llist, (*llist)->data));
	printf("%d exists: %d\n", *llist, llist_exist(*llist, *llist));

	/* Deep copy: llist_copy_deep */
	Node** llist_copy = llist_copy_deep(*llist, copyInt);
	llist_clear(llist);

	llist_print(*llist_copy, printInt);
	printf("\n");
}