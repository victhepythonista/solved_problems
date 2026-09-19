#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node * next;
}Node;


void addNext(Node ** node_ptr)
{
	// 
	int d =30;

	Node * new = (Node*)malloc( sizeof(Node) );
	new ->data = d;
	new -> next = NULL;
// 

	(*node_ptr)->next = new;
	printf("data %d ... %d..next node set to ..... %p \n",
	 (*node_ptr)->data , new->data , (*node_ptr)-> next);
	*node_ptr = new;
	// free(new);
}
void main()

{

	Node * test_node = (Node*)malloc(sizeof(Node));
	Node ** test_node_ptr ;
	*test_node_ptr = test_node; 
	addNext(test_node_ptr);
	printf("New node data %d\n", (*test_node_ptr)->data );
	free(test_node);
// quick practice on structs
}