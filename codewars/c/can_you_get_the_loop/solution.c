#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_t Node;
struct node_t {
  const Node* next;
};
int loop_size(const Node* node);


void main()

{

  Node n1, n2, n3, n4;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n2;

	int result = loop_size(&n1);
	int expected = 3;


	printf("Check result :  ");
	if (expected == result)
	{
		printf("OK\n");
	}else
	{
		printf("FAILED TEST . got %d instead of %d \n", result ,expected );
	}
}

/*

 GIVEN the node and guaranteed a loop is present
 we can have two pointers , a fast_pointer and slow pointer
 the fast one moves +2 while the slow one moves +1
 if you let them go from the same starting point the fast one will eventually
 loop over and catch up with the slow one 
 the point at which they meet is for sure a point in the loop, so it's safe 
 to loop again from there and measure the loop

*/

int loop_size(const Node* node) {
	if (node->next == NULL ) return 0;
	 if (node->next == node) return 1;
	int size = 0 ; 
	Node *fast_pointer , *slow_pointer;
	fast_pointer = (Node*)node; 
	slow_pointer = (Node*)node;
	// loop to detect the loop XD
	while (fast_pointer != NULL && fast_pointer->next != NULL)
	{
		fast_pointer = (Node*)fast_pointer -> next -> next;
		slow_pointer = (Node*)slow_pointer -> next;
		if (slow_pointer == fast_pointer)break;

	}

	// loop to count /measure the loop size
	 	slow_pointer = (Node*)slow_pointer->next;
	 	size ++;
	 	 
	while (slow_pointer != NULL && slow_pointer->next != NULL)
	 {
		if (slow_pointer == fast_pointer)break;
	 	slow_pointer = (Node*)slow_pointer->next;
	 	size ++;

	 }
	 return size;
}
