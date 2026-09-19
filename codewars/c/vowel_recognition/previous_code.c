#include <stdio.h>
#include <string.h>

unsigned long long vowel_recognition(const char *s);
void count_vowels(unsigned long long int *result_pointer , char *reader);

void main()

{
	printf("Testing...\n");

	char test_string[] = "aeiouAEIOU";
	unsigned long long int expected ,result;
	expected = 220;
	result =  vowel_recognition((const char *)&test_string);
	printf("expected : %lli ....got %lli\n",  expected  ,result); 
}


unsigned long long vowel_recognition(const char *s) {


	char * reader ;
	reader = (char*)&s[0]; // set the reader to the address of the first charachter...already by default but just why not
	unsigned long long int total = 0 ; 
	unsigned long long int *total_ptr = &total;
	count_vowels(total_ptr , reader);
	return total;
}



void count_vowels(unsigned long long int *result_pointer , char *reader)
{
	if (*reader == '\0')
	{
		return ;
	}
	char letter ;
	int remaining_chars = strlen(reader)  ; // find the remainder till the endn 
	char  text[remaining_chars + 1] ;
	text[0] = '\0'; // always null terminate :) 
	// loop through combinations
	for (int i = 1; i <= remaining_chars; ++i)
	{
		
		text[0] = '\0';
		strncpy(text , reader , i  );
		text[i] = '\0'; // null terminate, never trust strncpy :)
		for (unsigned long int k = 0; k < strlen(text); k++)
		{
			letter = text[k];
			// chjeck if a letter is a vowel
			if (
				letter == 'a' ||
				 letter == 'e' ||
				 letter == 'i' ||
				 letter == 'o' ||
				 letter == 'u' ||
				 letter == 'A' ||
				 letter == 'E' ||
				 letter == 'I' ||
				 letter == 'O' ||
				 letter == 'U' 

				 )
			{

				(*result_pointer)++;
			}
		}
	}
			count_vowels(result_pointer , reader + 1);// loop again . yolo

	}