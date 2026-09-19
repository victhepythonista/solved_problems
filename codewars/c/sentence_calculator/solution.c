
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define CHAR_a_VALUE_ON_ASCII_TO_INT_TABLE 97

int letters_to_numbers(const char *str) ;
int getValue(char x);


void main()

{

	int expected = 75;
	char test_string[] = "Give me 5!";

	int result = letters_to_numbers((char *)&test_string); 
	if (expected == result)
	{
		printf("TEST OK :)\n");
	}else
	{
		printf("Test not ok. got %d instead of %d\n",result , expected );
	}
}


/* returns the corresponding value of a chrachter  */
int getValue(char x)
{
	// check if its a digit and return it 
	if (isdigit(x) != 0)return x - '0';
	// check if lwtter
	//if letter return int value
	if (isalpha(x) != 0)
	{
		 int char_value;
		 char_value = (int)(tolower(x)) -( CHAR_a_VALUE_ON_ASCII_TO_INT_TABLE - 1 );// minus 1 to make 'a'  to be equal to 1, b = 2 ,..
		 if isupper(x)return char_value * 2 ;
		 return char_value;
	}
	// by default return 0
	return 0;

}
int letters_to_numbers(const char *str) { 

	int total = 0; // to return
	for (int i = 0; i < strlen(str); ++i)
	{
		total += getValue(str[i]);
	}
  return total; // <--- hajime!
}

