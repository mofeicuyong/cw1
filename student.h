
#ifndef _STUDENT_GUARD__H 
#define _STUDENT_GUARD__H
#include "book_management.h"
#include <stdio.h>
typedef struct _Student {
	    char *id; 
		char *password; 
		Book bro[100];
		struct _Student *next; 
}Student;

void create_a_student_link();
int Borrow_book(Book *head);

int return_book(Book *head);

int register_id(Student *hh);

int log_in(Student *hh);
#endif
