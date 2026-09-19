

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#define NAMELIM     0x8 //name limit 



struct student {
    char name[NAMELIM+1];
    unsigned fives;
    unsigned tens;
    unsigned twenties;
};

const char *most_money(const struct student *v, size_t n);


void main()

{


	printf("Tsting .....\n");
	const struct student students[] =  { {"Cameron",2,2,0}, {"Geoff",0,23,0}, {"Phil",2,2,1} };
	size_t size = 3;
	const char * result ;
	result =  most_money(&students[0] , size);

	char expected[] = "Geoff";

	if (0 == strcmp((char *)&expected , result ))
	{
		printf("TEST OK ! \n");
	}else{
		printf("Expected %s but got %s\n", expected , result );
	}

}

int getTotal(struct student * st )
{
	int total = ((st)->fives * 5) + ((st)->tens * 10) + ((st)->twenties * 20) ;
	return total;
}

const char *most_money(const struct student *v, size_t n)
{

	if ( (int)n== 1)
	{
		return v->name;
	}
	int totals[n];
	int all_money = 0;
	char *result;
	result = NULL;
	int brokest = getTotal((struct student*)v) ; // assign total from any student
	int highest = brokest;
	int richest_index;
	int student_total; // to hold the total number of one student
	// get the totals
	for (int i = 0; i < (int)n; ++i)
	{
		student_total = getTotal(( struct student*)v+i);
		if (highest < student_total)
		{
			highest = student_total;
			richest_index = i; 
		}
		if (brokest > student_total) brokest = student_total ;
		totals[i] = student_total;
	}
	// check if all have equal amounts of money
	if (highest == brokest)
	{
		return strdup("all");
	}
	int name_length = strlen((v+richest_index)->name) ; 
	result = (char*)malloc(1 + sizeof(char)*name_length);
	strcpy(result , (v+richest_index)->name );
	// get the one with the most amount of money
    return result;

}