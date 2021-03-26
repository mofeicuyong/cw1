#include "book_management.h"
#include<string.h>
#include<stdlib.h>
#include "interface.c"
//saves the database of books in the specified file
//returns 0 if books were stored correctly, or an error code otherwise
int store_books(FILE *file,Book*head)
{

	if(head != NULL)
  { 
    Book *p = head->next;
    file = fopen("file.txt", "a+");
    if(file != NULL)
    {
      while(p != NULL)
      {
        fprintf(file, "%d %s %s %d %d\n", p->id,p->title, p->authors, p->year, p->copies);
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

//loads the database of books from the specified file
//the file must have been generated by a previous call to store_books()
//returns 0 if books were loaded correctly, or an error code otherwise
int load_books(FILE *file,Book*head)
{
	
	file = fopen("file.txt", "a+");
 	Book* book;
  	if (file != NULL) {
    while (fscanf(file, "%d %s %s %d %d", &book->id, &book->title, &book->authors, &book->year, &book->copies) != EOF) 
	{
      if(head != NULL)
  		{
			Book *node;
			node = (Book *)malloc(sizeof(Book));
			node=book;
			node = node->next;
			if(node != NULL)
    		{
      		Book* p = head;
      		while(p->next != NULL)
        	p = p->next;
			p->next = node;
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

//adds a book to the ones available to the library
//returns 0 if the book could be added, or an error code otherwise
int add_book(Book* head)
{
	int i=0;
	int j=0;
	Book *node1;
	node1 = (Book *)malloc(sizeof(Book));
	node1->authors = (char*)malloc(sizeof(char)*50);
	node1->title = (char*)malloc(sizeof(char)*50); 
	printf("Enter the title of the book you wish to add:");
	scanf("%s",node1->title);
	printf("Enter the author of the book you wish to add:");
	scanf("%s",node1->authors);
	printf("Enter the year that the book you wish to add was released:");
	scanf("%d",&node1->year);
	printf("Enter the number of the copies of the book that you wish to add:");
	scanf("%d",&node1->copies);
	Book *a=head;
	while(a->next!=NULL)
	{
	j++;
	a = a->next;
		if(strcmp(node1->title,a->title)==0)
		{
			printf("Book has been already added!");
		}
		else
		{
			i++;
		}
	}
	a=head;
	if(i==j)
	{
		node1->id = j;
		while(a->next!= NULL)
		{
        a = a->next;
    	}
      	a->next = node1;
		printf("Book was successfully added!\n");
		return 0;
	}
}
//removes a book from the library
//returns 0 if the book could be successfully removed, or an error code otherwise.
int remove_book(Book*head)
{
	Book book;
	Book *p = head;
	printf("Enter the ID number of the book you wish to remove:");
	scanf("%d",&book.id);
	while(p->next!=NULL)
	{
	if(p->next->id==book.id)
	{
	Book* pr=p->next; 
	p->next=pr->next;
	free(pr);
	printf("Book was successfully removed");
	return 0;
	}
	p=p->next;
	}
}

//finds books with a given title.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.

BookArray find_book_by_title (Book*head,Book*h)
{
	int flag=0;
	char* title;
	printf("Please enter the title:");
	title = (char*)malloc(sizeof(char)*50);
	scanf("%s",title);
	getchar();
	BookArray BookArray;
	BookArray.length=0;
	Book *k=h; 
	Book *p= head;
	while(p->next!=NULL)
	{
		p=p->next;
		if (strcmp(p->title,title)==0)
		{
			flag=1;
			
			BookArray.length++;
			if(BookArray.length==1)
			{
				BookArray.array=p;
			}
			while(k->next!=NULL)
			{
				k=k->next;
			}
			k->next=p;
		}
	}
	if(flag==0)
	{
		BookArray.array=NULL;
		BookArray.length=0;
	}
	return BookArray; 
}

//finds books with the given authors.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
BookArray find_book_by_author (Book* head,Book*h)
{

	char* author;
	printf("Please enter the author:");
	author = (char*)malloc(sizeof(char)*50);
	scanf("%s",author);
	BookArray BookArray;
	BookArray.length=0;
	Book *k=h; 
	int flag=0;
	Book *p= head;
	while(p->next!=NULL)
	{
		p=p->next;
		if (strcmp(p->authors,author)==0)
		{
			flag=1;
			
			BookArray.length++;
			if(BookArray.length==1)
			{
				BookArray.array=p;
			}
			while(k->next!=NULL)
			{
				k=k->next;
			}
			k->next=p;
		}
	}
	if(flag==0)
	{
		BookArray.array=NULL;
		BookArray.length=0;
	}
	return BookArray; 
}
//finds books published in the given year.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
BookArray find_book_by_year (Book *head,Book*h)
{
	int year;
	BookArray BookArray;
	printf("Please enter the year:");
	scanf("%d",&year);
	BookArray.length=0;
	Book *k=h; 
	int flag=0;
	Book *p= head;
	while(p->next!=NULL)
	{
		p=p->next;
		if (p->year==year)
		{
			flag=1;
			
			BookArray.length++;
			if(BookArray.length==1)
			{
				BookArray.array=p;
			}
			while(k->next!=NULL)
			{
				k=k->next;
			}
			k->next=p;
		}
	}
	if(flag==0)
	{
		BookArray.array=NULL;
		BookArray.length=0;
	}
	return BookArray; 
}

void search(Book*head,Book*h)
{
	int b;
	int re=0;
	while(re==0)
	{
	
	menu3();
	scanf("%d",&b);
	Book* k;
	switch(b)
							{
								case 1:
									
									k = find_book_by_title (head,h).array;
									if(k==NULL)
									{
									printf("There is no such book.\n");
									}
									else
									{
										while(k!=NULL)
										{
										printf("%d %s %s %d %d",k->id,k->title,k->authors,k->year,k->copies);
										k=k->next;
										}
									}
									continue;
								case 2:
									
									
									k = find_book_by_author (head,h).array;
									if(k==NULL)
									{
									printf("There is no such book.\n");
									}
									else
									{
										while(k!=NULL)
										{
										printf("%d %s %s %d %d",k->id,k->title,k->authors,k->year,k->copies);
										k=k->next;
										}
									}
									continue;
								case 3:
									
									
									k = find_book_by_year (head,h).array;	
									if(k==NULL)
									{
									printf("There is no such book.\n");
									}
									else
									{	
										while(k!=NULL)
										{
										printf("%d %s %s %d %d",k->id,k->title,k->authors,k->year,k->copies);
										k=k->next;
										}
									}
									continue;
								case 4:
									re=1;
									break;
								default:
      								printf("Illegal input!\n");
      								continue;
      							}
      	}
}
