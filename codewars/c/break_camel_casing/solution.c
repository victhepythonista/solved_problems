
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
 

char* solution(const char *camelCase) ;



void main()

{
  char test_input[] = "thisIsAVeryLongIdentifierName";
  char expecting[] = "this Is A Very Long Identifier Name";

  char * result = solution((const char *)&test_input);

  if (strcmp(result , (char*)&expecting) == 0)
  {
    printf("MATCH! ALL OK :)\n");
  }
  else
  {

  printf("Expected %s ,but got %s .....do better Victor!!", (char*)&expecting , result);
  }

  free(result);

}

//returned buffer should be dynamically allocated and will be freed by a caller
char* solution(const char *camelCase) {
  int original_length = strlen(camelCase); // length of original  string 
  int result_size =  original_length +1;
  char previous , current ; // to compare and change when looping 
  char * result = (char*)calloc(1 , ( result_size ));
  char * temp_result ; // a cache for the result pointer when reallocating memory later on
    bool add_space = false; // will be used when looping
  temp_result = NULL;
  strcpy(result , camelCase);
  result[original_length] = '\0';

  /// check if the string is sizeable
  if (original_length == 0) return result; // empty string
  if (original_length == 1)
  {
    result[1] = '\0';
    return result;
  }


  // add the first charachter to the result so that we have a 'previous' item before looping
  previous = camelCase[0];
  result[0] = previous; // clear the string
  result[1] = '\0';
  result_size = strlen(result ) + 1;

  /*
   loop the original string(char * camelCase ) while adding data to the new string(char * result) and
    reallocating as needed
  */
  for (int i = 1 ; i < original_length; i++)
  {
    
    current  = camelCase[i];
    // check if we need to space the current and previous charachters 
    if ((isupper(current)  && islower(previous)) || ( isupper(current) && isupper(previous) ))
    {
      // reallocate +1 byte for the whitespace
      result_size ++;

      add_space = true;

    }

      // Increase the resultsize as required 
      result_size ++;// space for new char 
      temp_result  = (char *)realloc(result , result_size );
      // pointer should be checked if valid here under normal conditions
      result = temp_result;
      temp_result = NULL;
      if (add_space)
      {

      result[result_size-3] =' ';
      result [result_size-2] = current;
      result[result_size-1] = '\0';
      add_space = false;
      }else{

      result [result_size-2] = current;
      result[result_size-1] = '\0';
      }

     
    previous = current; // set the previous charachter


  }



  return result;
}

