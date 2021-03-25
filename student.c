#include "book_management.h"
#include "student.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
Student* i;

int register_id(Student *hh)
{
	int flag=0;
	Student *d;
	d=hh;
	i = (Student*)malloc(sizeof(Student));
	i->id = (char*)malloc(sizeof(char)*50);
	i->password = (char*)malloc(sizeof(char)*50);
	printf("Please enter your user name:");
	scanf("%s",i->id);
	getchar();
	while(strcmp(i->id,"librarian")==0)
		{
			printf("You can not register this name.Please type another one.\n");
			printf("Please enter your user name:");
			scanf("%s",i->id);
			getchar();
		}
	while(d->next!=NULL) 
	{
		d=d->next;
		if(strcmp(i->id,d->id)==0)
		{
		printf("This user name has been used.Please change another one.\n");
		flag=1;
		}
	}
	d=hh;
	if(flag==0)
	{
		printf("Please enter your password:");
		scanf("%s",i->password);
		getchar();
		while(d->next!= NULL)
		{
        d = d->next;
    	}
      	d->next = i;
      	printf("Register successfully!\n");
		return 1;
	}
	
}
int log_in(Student *hh)
{
	Student *k;
	i = (Student*)malloc(sizeof(Student));
	k=hh;
	int flag=0;
	i->id = (char*)malloc(sizeof(char)*50);
	i->password = (char*)malloc(sizeof(char)*50);
	printf("Please enter your user name:");
	scanf("%s",i->id);
	getchar();
	printf("Please enter your password:");
	scanf("%s",i->password);
	getchar();
	if(strcmp(i->id,"librarian")==0&&strcmp(i->password,"librarian")==0)
	{
		return 1;
	}
	else
	{
		if(k==hh)
		while(k->next!=NULL)
		{
			k=k->next;
			if(strcmp(k->id,i->id)==0&&strcmp(k->password,i->password)==0)
			{
				flag=1;
				return 0;
			}
		}
		if(flag==0)
		{
			printf("Wrong user name or wrong password.\n");
			return -1;
		}
	}
	
}
int Borrow_book(Book *head)
{
	Book* m=head;
	int di;
	int flag=0;
	printf("Please enter which book you want to borrow:");
	scanf("%d",&di);
	while(m->next==NULL)
	{
		if(di==m->id)
		{
			flag=1;
			if(m->copies>0)
			{
			m->copies--;
			printf("you borrow this book successfully!");
			
			}
			else
			{
				printf("");
				return 0;
			}
		}
		m=m->next;
	}
	if(flag==0)
	{
		printf("");
		return 0;
	}
}
int return_book(Book *head)
{
	Book* m=head;
	int di;
	int flag=0;
	printf("");
	scanf("%d",&di);
	while(m->next==NULL)
	{
		if(di==m->id)
		{
			flag=1;
			m->copies++;
			printf("");

		
		}
		m=m->next;
	}
	if(flag==0);
	{
		printf("");
	}
	
}


