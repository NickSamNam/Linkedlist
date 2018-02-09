#pragma once
#include "printer.h"

typedef struct _Node Node;

Node* llist_create(int length);
void llist_add(Node* llist, void* data);
void llist_add_i(Node* llist, int index, void* data);
void llist_print(Node* node, printer printer);

struct _Node {
	void* data;
	Node* next;
};