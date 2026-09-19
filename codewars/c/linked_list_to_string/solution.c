#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>



// "Preloaded Code" (do NOT modify!)
typedef struct node {
  int data;
  struct node *next;
} Node;

// Main Solution
char *stringify(Node *list) {
  // TODO: Return a string representation of the linked list provided
  /*
   My approach is to first loop through all nodes first
	 in order to determine the size of the string 
	
		Lastly loop again this time generating the string adding content with
		every loop until 'NULL' is the next node

	 */
	char joiner[] = " -> ";
	int joiner_size = strlen(joiner);
	int total_nodes = 0;
	int string_size = 0;
	char end[] =  "NULL";
	char value[11]; // 10 charachters is the max for positive integers , 1 for null terminator
	value[0] = '\0';
	 Node * current_node = list;
	 Node * previous_node  = NULL;
	// find the number of nodes
	// find the size of the string and allocate memory 
	 	if (current_node == NULL)
	{
		return strdup("NULL");
	}
	while (true)
	{
		if (current_node->next == NULL )
		{
			// last item in list 
				sprintf(value ,"%d" ,current_node->data);
		string_size +=  strlen(value);
	 	total_nodes ++;
			break;
		}
		sprintf(value ,"%d" ,current_node->data);
		string_size +=  strlen(value);
		strcpy(value, "");// empty the value in nprep or the next loop
		previous_node = current_node;
		current_node =previous_node->next;
	 	total_nodes ++;
	}
	// string size only covers the length of the data
	// now to add space for the joiners and the null terminator
	string_size += (strlen(joiner) * total_nodes) ;
	string_size += strlen(end); // space for 'NULL'
	string_size += 1; // null terminator
	char * result =  (char*)calloc(1 ,string_size );
	result[0] = '\0'; 

	// reset the current node in prep to loop again
	current_node = list;
	char to_add[joiner_size + 11]; // 11 or max num of charachters(10) and 1 or null terminator
	to_add[0] = '\0';
	if (current_node == NULL)
	{
		return result;
	}
	// generate the string using a while loop
	while (true)
	{

		if (current_node->next == NULL )
		{
			// last item in the string
		sprintf(to_add , "%d%s%s" , current_node->data , joiner ,end);
		strcat(result , to_add);
			break;
		}
			previous_node = current_node;
		current_node =previous_node->next;
		sprintf(to_add , "%d%s" , previous_node->data , joiner);
		strcat(result , to_add);
		to_add[0] = '\0'; //empty the string for the next loop
	 	
	}
	// return the string
  return result;
}

int main()
{

	Node  n1 , n2 , n3;
	n1.data =0;
	n2.data =1; 
	n3.data = 2;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;

	char * as_string = stringify(&n1);
	if (as_string == NULL) 
	{
		return 0;

	}else{
printf("string is : '%s' with lwength %zu \n",as_string , strlen(as_string));
	free(as_string);
		}

return 0;

}