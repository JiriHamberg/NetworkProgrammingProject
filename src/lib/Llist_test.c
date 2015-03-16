#include "../linked_list.h"

/*
 * Assert based tests for linked list implementation.
 *
 */
void main(int argc, char** argv) {
	int a = 3;
	int b = 5;
	int c = 7;

	Llist *l = Llist_new();
	assert(l -> size == 0);

	Llist_add(l, &a);
	assert(l -> size == 1);

	Llist_add(l, &b);
	assert(l -> size == 2);

	Llist_add(l, &c);
	assert(l -> size == 3);

	/*
	printf("a = %d, b = %d, c = %d, a = %d\n",
		*(int *)(l -> head -> value),
		*(int *)(l -> head -> next -> value),
		*(int *)(l -> head -> next -> next -> value),
		*(int *)(l -> head -> next -> next -> next -> value));
	*/

	assert(*(int *)(l -> head -> value) == 3);
	assert(*(int *)(l -> head -> next -> value) == 5);
	assert(*(int *)(l -> head -> next -> next -> value) == 7);
	assert(*(int *)(l -> head -> next -> next -> next -> value) == 3);

	Llist_remove(l, l -> head -> next);
	assert(l -> size == 2);

	/*
	printf("a = %d, c = %d, a = %d, c = %d\n",
		*(int *)(l -> head -> value),
		*(int *)(l -> head -> next -> value),
		*(int *)(l -> head -> next -> next -> value),
		*(int *)(l -> head -> next -> next -> next -> value));
	*/
	assert(*(int *)(l -> head -> value) == 3);
	assert(*(int *)(l -> head -> next -> value) == 7);
	assert(*(int *)(l -> head -> next -> next -> value) == 3);
	assert(*(int *)(l -> head -> next -> next -> next -> value) == 7);

	Llist_remove(l, l -> head);
	assert(l -> size == 1);	

	/*
	printf("c = %d, c = %d, c = %d\n",
		*(int *)(l -> head -> value),
		*(int *)(l -> head -> next -> value),
		*(int *)(l -> head -> prev ->  prev -> value));	
	*/
	assert(*(int *)(l -> head -> value) == 7);
	assert(*(int *)(l -> head -> next -> value) == 7);
	assert(*(int *)(l -> head -> prev ->  prev -> value) == 7);

	Llist_remove(l, l -> head);
	assert(l -> size == 0);
	assert(l -> head == NULL);
	exit(0);
}