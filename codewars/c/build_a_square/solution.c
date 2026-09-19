#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>


// Return a dynamically allocated, null-terminated string.

char* generate_shape(size_t n) {
    int num = (int)n;
    char row[n+2];
    // n bytes for the "*" chars
    // 1 byte for the null termiternator
    // and 1 for the escape sequence
    int shape_size = (((int)sizeof(char) * num) + 1)*num ;
    shape_size ++;
    printf("shape_size --> %d \n" , shape_size);
    // allocate memory for the shape
    char * shape = (char*)malloc( shape_size);
    shape[0] = '\0';
    if(shape == NULL) return NULL;
    // create a row 
    for (int i = 0; i < num ; ++i)
    {
        row[i] = '+';

    }
    row[num] = '\n';
    // null terminate the row string 
    row[num+1] = '\0';
    // add the row to the shape n times 
    for (int i = 0; i < num; ++i)
        {
            // append the row
            strcat(shape , row);
        }    
    // remove the last escape sequence '\n' and null terminate the string
    shape[ shape_size -2] = '\0';
    return shape;
}


void main(){


    // test shape generation here 
    size_t test_num = 3;
    char * result = generate_shape(test_num);
    if (result == NULL)
    {
        printf("Error generating shape. gotr NULL ");
    }
    printf("Result is : \n%s of length : %zu " , result ,strlen(result));
    for (int i = 0; i < strlen(result); ++i)
    {
        printf("--%c\n",result[i] );
    }
    free (result);
}