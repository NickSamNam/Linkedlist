#pragma once
#include "printer.h"

typedef struct _Node Node;

Node** llist_create();
Node** llist_create_l(int length);
void llist_add(Node** llist, void* data);
void llist_add_i(Node** llist, int index, void* data);
void llist_addAll(Node** llist, Node* other);
void llist_addAll_i(Node** llist, int index, Node* other);
void llist_remove_i(Node** llist, int index);
void llist_remove_e(Node* llist, void* data);
void llist_print(Node* node, printer printer);

struct _Node {
	void* data;
	Node* next;
};