#include "../linked_list.h"


Llist *Llist_new(void) {
	Llist *new_l;
	new_l = (Llist *)malloc(sizeof(Llist));
	new_l -> size = 0;
	new_l -> head = NULL;
	return new_l;
}

bool Llist_empty(Llist *l) {
	return l -> head == NULL;
}

void Llist_add(Llist *l, void *value) {
	Llist_node *last, *new;	

	new = (Llist_node *)malloc(sizeof(Llist_node));
	new -> value = value;

	if (Llist_empty(l)) {
		new -> next = new;
		new -> prev = new;
		l -> head = new;
		l -> size += 1;
		return;
	}

	last = l -> head -> prev;	
	last -> next = new;
	l -> head -> prev = new;
	new -> prev = last;
	new -> next = l -> head;
	l -> size += 1;
}

void Llist_remove(Llist *l, Llist_node *node) {
	assert(l -> size > 0);
	
	if(node == l -> head) {
		if(l -> size == 1) {
			l -> head = NULL;
		} else {
			l -> head = l -> head -> next;
		}
	}
		
	Llist_node *pprev, *nnext;
	pprev = node -> prev;
	nnext = node -> next;

	pprev -> next = nnext;
	nnext -> prev = pprev;	

	l -> size -= 1;
	free(node);
}