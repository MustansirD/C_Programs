#ifndef PERSON_PRIVATE_H
#define PERSON_PRIVATE_H

typedef struct
{
	char first_name[32];
	char last_name[32];
	unsigned int birth_year;
}person_t;

#endif