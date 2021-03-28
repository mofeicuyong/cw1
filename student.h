
#ifndef _STUDENT_GUARD__H 
#define _STUDENT_GUARD__H
#include "book_management.h"
#include <stdio.h>
typedef struct _Student {
		int idi;
	    char *id; 
		char *password; 
		Book* bro;
		struct _Student *next; 
		int book;
}Student;

int Borrow_book(Book *head,int sid,Student*hh,Book*hhh);

int return_book(Book *head,int sid,Student*hh,Book*hhh);

int register_id(Student *hh);

int log_in(Student *hh);

int store_student(FILE *file,Student *hh,Book* hhh);

int load_student(FILE *file,Student*hh,Book* hhh);
#endif
