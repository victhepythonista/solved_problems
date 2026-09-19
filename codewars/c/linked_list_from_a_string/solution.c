#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>



// "Preloaded Code" (do NOT modify!)
typedef struct node {
  int data;
  struct node *next;
} Node;

Node *parse(const char *string);
int countString(char *big_string, char *sub_string);
void addNewNode(Node **current_node_ptr , char * data  );

void main()

{



   
    char hello[] = "hello";
    char find[] = "l";
    int count = countString((char*)hello , (char*) find );
    printf("Count string test --> 2 == %d \n" , count    );
    printf("Tsting parse function\n");


    char test_linked_list_string[] = "13333 -> 2 -> 3 -> NULL";
    Node * result = parse(test_linked_list_string);

    printf("Testing node ....\n");

    Node * read = NULL ;
    Node * read_cache = NULL ;

    read =result;
    if (result == NULL)
    {
        return;
    }
    printf("\n-------------------------\nCleaning Received nodes starting with NODE : %d : %p\n", read->data , &read );
    while (read != NULL)
    {
        printf("NODE | %d | %p \n", read -> data , read -> next );
        if (read -> next == NULL)
        {
            printf("Freeing node and ending loop\n");
            free(read);
            break;
        }
        printf("Freeing node memory %p %d\n" , &read , read->data);
        read_cache = read;
        read = read_cache -> next;

        free(read_cache);
    }
    // 



}


Node *parse(const char *string)
/*  
returns the first node from the linked list generated
returns : first_node 

- */
{


    char * s = strdup(string);
    char empty_node_in_string[] = "NULL";
    // check if the string is just one NULL node
    if (strcmp(s, empty_node_in_string) == 0)return NULL;
    Node * head = NULL;
    Node * first_node = NULL;
    char * reader = &s[0]; // for reading the string..set to start at where node data starts 
    int max_number_length = 10; // maximum number of charachters expected 
    char  number_string[max_number_length + 1 ]; // +1 for the null tmntr
    number_string[0] = '\0';
    char joiner[] = " -> ";
    int joiner_size = strlen(joiner);
    char * next_joiner_start = NULL; // 
    ptrdiff_t number_length ;
    // locate the first node , this is what will be returned
    next_joiner_start = strstr(s , joiner);
    number_length =  next_joiner_start - reader; 
    strncpy((char *)&number_string ,reader , (int)number_length);
    head = (Node*)malloc(sizeof(Node));
    head -> data = atoi((char*)number_string);
    first_node = head ; // STORE THE FIRST NODE
    // set the reader to just after the fisrt joiner 
    reader = next_joiner_start + joiner_size;
    Node **head_ptr = &head;
    // loop through the string adding the other nodes until the end 
    while (true)
    {
        if (reader == NULL)
        {
            // welp, end of the string
            break;
        }
        if (strcmp( (char*)&empty_node_in_string , reader  ) == 0)
        {
            // end of string ,  assumING the last node's next variable is set to NULL
            break;
        }
        number_string[0] = '\0';
        // get the data for a new node
        next_joiner_start = strstr(reader , joiner);
        number_length =  next_joiner_start - reader;
        strncpy( (char*)&number_string ,(const char *) reader , (int)number_length  );        
        number_string[number_length] = '\0';
        // add a new node now that we have data for a new node
        addNewNode(head_ptr , (char*)&number_string);
        reader = next_joiner_start + joiner_size;


    }

    return  first_node;


}


 
int countString(char *big_string,   char *sub_string){
    // returns the number of times a sub-string string appears in
    int count = 0;
    char *tmp = big_string;
    while(true)
    {
        tmp = strstr(tmp, sub_string);
        if (tmp == NULL)
        {
            return count;
        }
        count++;
        tmp++;
    }
    return count;
}


void addNewNode(Node **current_node_ptr , char * data  )
{
    // make the new node
    Node * new = NULL;
    new = (Node * )malloc(sizeof(Node)); // allocate for new node
    new -> data = atoi(data);
    new -> next = NULL; // set next node to null
    (*current_node_ptr) -> next = new; // inform the previous node of the new node XD
    *current_node_ptr  = new; // set the current_node_ptr to the new node's addr

}