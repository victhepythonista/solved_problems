#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void scramble(size_t length, const char *string, const size_t array[length], char *) ;



void main()

{

	const char test_string[] = "retb";
	size_t l = 4;
	const size_t arr[4] = {2,1,3,0};
	char * expected = "bert";
	char res[l + 1];
	res[0] = '\0';
	scramble(l , (const char*)&test_string , arr , (char*)&res );
	printf("Scrampled string : %s \n" , res);

}


void scramble(size_t length, const char *string, const size_t array[length], char *result) {

    //  <----  hajime!
	char to_move ;
	size_t new_location;

    // loop the string and the array at the same time placing the numbers
    // thanks to the items in the array and charachters in the string corresponding. so one loop suffices 
    for (size_t i = 0; i < length; ++i)
    {
    	to_move =  string[i];
    	new_location =  array[i];
    	result[new_location] = to_move; 
    }
    result[length] = '\0'; // null terminate :)



}