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
	int j=0;
	i = (Student*)malloc(sizeof(Student));
	i->id = (char*)malloc(sizeof(char)*50);
	i->password = (char*)malloc(sizeof(char)*50);
	printf("Please enter your user name:");
	getchar();
	scanf("%[^\n]s",i->id);
	getchar();
	while(strcmp(i->id,"librarian")==0)
		{
			printf("You can not register this name.Please type another one.\n");
			printf("Please enter your user name:");
			scanf("%[^\n]s",i->id);
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
		j++;
	}
	d=hh;
	if(flag==0)
	{
		printf("Please enter your password:");
		scanf("%[^\n]s",i->password);
		getchar();
		while(d->next!= NULL)
		{
        d = d->next;
    	}
      	d->next = i;
      	i->book=0;
      	d->next->next=0;
      	i->idi=j;
      	printf("Register successfully!\n");
		return 1;
	}
	
}
int log_in(Student *hh)
{
	Student *k;
	i = (Student*)malloc(sizeof(Student));
	k=hh;
	int ab=0;
	int flag=0;
	i->id = (char*)malloc(sizeof(char)*50);
	i->password = (char*)malloc(sizeof(char)*50);
	printf("Please enter your user name:");
	getchar();
	scanf("%[^\n]s",i->id);
	getchar();
	printf("Please enter your password:");
	scanf("%[^\n]s",i->password);
	getchar();
	if(strcmp(i->id,"librarian")==0&&strcmp(i->password,"librarian")==0)
	{
		return -2;
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
				ab=k->idi;
				return ab;
			}
		}
		if(flag==0)
		{
			printf("Wrong user name or wrong password.\n");
			return -1;
		}
	}
	
}
int Borrow_book(Book *head,int sid,Student*hh,Book*hhh)
{
	Student*k;
	Book* m=head;
	Book* w=hhh;
	Book *node;
	node = (Book*)malloc(sizeof(Book));
	node->title =(char*)malloc(sizeof(char)*50);
	node->authors =(char*)malloc(sizeof(char)*50);
	int di;
	int flag=0;
	printf("Please enter the id of the book you want to borrow:");
	scanf("%d",&di);
	while(m->next!=NULL)
	{
		m=m->next;
		if(di==m->id)
		{
			flag=1;
			if(m->copies>0)
			{
			k=hh;
			while(k->next!=NULL)
			{
				k=k->next;
				if(k->idi==sid)
				{
					k->book++;
					if(k->book==1)
					{
					k->bro=m;
					}
					while(w->next!=NULL)
					{
						w=w->next;
					}
					if(w->id==di)
					{
						printf("You have already borrowed this book.\n");
						return 0;
					}
					node->title=m->title;
					node->authors=m->authors;
					node->id=m->id;
					node->year=m->year;
					node->copies=1;
					w->next=node;
					w->next->next=0;
					m->copies--;
				}
			}
			
			printf("you borrow this book successfully!\n");
			}
			else
			{
				printf("This book has no more left!");
				return 0;
			}
		}
	}
	if(flag==0)
	{
		printf("Fail to find this book.\n");
		return 0;
	}
}
int return_book(Book *head,int sid,Student* hh,Book*hhh)
{
	Book* m=head;
	int di;
	Book *we=hhh;
	int flag=0;
	Student*k=hh;
	int flag2=0;
	while(k->next!=NULL)
			{
				k=k->next;
				if(k->idi==sid)
				{
								while(we->next!=NULL)
								{
									flag2=1;
									we=we->next;
									printf("%d %s %s %d %d",we->id,we->title,we->authors,we->year,we->copies);
									printf("\n");
								}
						
				}
			}
	if(flag2==0)
	{
		printf("You have no book need to return.\n");
		return 0;
	}
	printf("Please enter the id of the book you want to return:");
	scanf("%d",&di);
	we=hhh;
	while(m->next!=NULL)
	{
		m=m->next;
		if(di==m->id)
		{
			m->copies++;
			flag=1;
			while(we->next!=NULL)
			{
				if(we->next->id==di)
				{
						Book* pr=we->next; 
						we->next=pr->next;
						free(pr);
					
				}
				if(we->next!=NULL)
				we=we->next;
			}
			printf("You have return the book successfuly!\n");
		}
	}
	if(flag==0)
	{
		printf("You may type a wrong id.\n");
	}
	
}

int store_student(FILE *file,Student *hh,Book* hhh)
{
	if(hh != NULL)
  { 
    Student *p = hh->next;
    Book* k=hhh->next;
    file = fopen("student.txt", "w+");
    if(file != NULL)
    {
      while(p != NULL)
      {
        fprintf(file, "%d %s %s %d\n", p->idi,p->id, p->password, p->book);
        while(k!=NULL)
        {
        	fprintf(file, "%d %s %s %d %d\n", k->id,k->title, k->authors, k->year, k->copies);
        	k=k->next;
		}
        p = p->next;
      }
      fclose(file);
      return 0; 
    }
	else {
      
      printf("fail to open the txt.Please check!\n");
    }  
  }
}

int load_student(FILE *file,Student*hh,Book* hhh)
{
	file = fopen("student.txt", "a+");
 	Student *p;

  	if (file != NULL) {
    while (!feof(file)) 
    {
    p = (Student*)malloc(sizeof(Student));
 	p->id = (char*)malloc(sizeof(char)*50);
 	p->password= (char*)malloc(sizeof(char)*50);
		fscanf(file, "%d %s %s %d\n", &p->idi,p->id, p->password, &p->book);
			if(p != NULL)
    		{
			Student* w=hh;
      		while(w->next != NULL)
      		{
        	w = w->next;
        	}
			w->next = p;
			w->next->next=0;
    		}
    		for(int m=0;m<p->book;m++)
    		{
    			Book* book=hhh;
    			book = (Book*)malloc(sizeof(Book));
 				book->authors = (char*)malloc(sizeof(char)*50);
 				book->title = (char*)malloc(sizeof(char)*50);
		fscanf(file, "%d %s %s %d %d\n", &book->id, book->title, book->authors, &book->year, &book->copies);
			if(book != NULL)
    		{
			Book* e = hhh;
      		while(e->next != NULL)
      		{
        	e = e->next;
        	}
			e->next = book;
			e->next->next=0;
    		}
			}
    }
    fclose(file);
    return 0;
  }

  else 
  {
    printf("fial to open the txt.Please check!\n");
    return 1;
  }
}
