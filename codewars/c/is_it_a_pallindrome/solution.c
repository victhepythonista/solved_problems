#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

bool is_palindrome(const char *str_in) {
	int length = strlen(str_in);
	if (length <= 1)
	{
		return true;
	}
	char reversed[length + 1];
	strcpy(reversed , str_in);
	char cache;
  // reverse the string 
	int l , r ; // left and right pointers for reversal
	l = 0;
	r = length-1;  
	while(l < r)
	{
		cache = reversed[l];
		reversed[l] = reversed[r];
		reversed[r] = cache; 
		l ++ ;
		r -- ;
	}
	reversed[length] = '\0'; // null terminate properly
	// loop through and ensure every charachter matches the corresponding one
	// in the reversed string , lower the case in each charachter comparison
	for (int i = 0; i < length; ++i)
	{
    // if any mismatch , return false
		if (tolower(reversed[i]) != tolower(str_in[i])) return false;
	}
	return true;
}
void main()

{
	char test_string[34] = "Aba";
 bool check = is_palindrome(test_string);

 printf("PALLINDROME CHECK : %s = %b \n", test_string , check );
}