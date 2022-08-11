#ifndef STUDENT_PUBLIC_H
#define STUDENT_PUBLIC_H

struct student_t* student_new();//memory allocation
void student_ctor(	struct student_t*,
					const char*,
					const char*,
					unsigned int,
					const char*,
					unsigned int);
					
void student_dtor( struct student_t* );

//Behavior functions
void student_get_first_name(struct student_t *, char*);
void student_get_last_name(struct student_t*,char*);
unsigned int student_get_birth_year(struct student_t*);
void student_get_student_number(struct student_t*, char*);
unsigned int student_get_passed_credits(struct student_t*);


#endif