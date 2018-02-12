#pragma once
#include "printer.h"
#include "copier.h"

typedef struct _Node Node;
struct _Node
{
	void* data;
	Node* next;
};

Node** llist_create();
Node** llist_create_l(int length);
void llist_add(Node** llist, void* data);
void llist_add_i(Node** llist, int index, void* data);
void llist_addAll(Node** llist, Node* other);
void llist_addAll_i(Node** llist, int index, Node* other);
void llist_remove_i(Node** llist, int index);
void llist_remove_e(Node** llist, void* data);
void llist_clear(Node** llist);
int llist_length(Node*);
int llist_exist(Node*, void* data);
Node** llist_copy_deep(Node* llist, copier copier);
void llist_print(Node* node, printer printer);