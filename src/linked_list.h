#include "common.h"

typedef struct __Llist_node{
	void *value;
	struct __Llist_node *next;
	struct __Llist_node *prev;
} Llist_node;


typedef struct {
	Llist_node *head;
	size_t size;
} Llist;

Llist *Llist_new(void);

bool Llist_empty(Llist *l);

void Llist_add(Llist *l, void *value);

void Llist_remove(Llist *l, Llist_node *node);

