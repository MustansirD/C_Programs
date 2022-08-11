#include<stdio.h>

typedef struct
{
	char first_name[32];
	char last_name[32];
	unsigned int birth_year;
}person_t;

typedef struct
{
	person_t person;
	char student_number[16];
	unsigned int passed_credits;
}student_t;

int main(int argc, char **argv)
{
	student_t s;
	student_t *ps_ptr1 = &s;
	person_t *ps_ptr2 = (person_t *)&s;
	printf("student pointer points to [%p]\n",(void *)ps_ptr1);
	printf("Person pointer points to [%p]\n",(void *)ps_ptr2);
	
	return 0;
}