#include "book_management .c"
#include "interface.c"
int main()
{
	head = tail = (Book*)malloc(sizeof(Book));
	h=t=(struct BookArray*)malloc(sizeof(BookArray));
	int a;
	char au;
	char ti;
	int y;
	while(1)
	{
		menu1();
		scanf("%d",a);
		switch(a)
		{
			case 1:
			
			case 2:
			
			case 3: 
				menu3();
				scanf("%d",a);
				switch(a)
				{
					case 1:
						printf("Please enter the title:");
						scanf("%s",ti);
						BookArray find_book_by_title (ti);
						BookArray *k=h;
						while(k->next!=NULL)
							{
							printf("%d %s %s %d %d",k->array->id,k->array->title,k->array->authors,k->array->year,k->array->copies);
							k=k->next;
							}
						continue;
					case 2:
						printf("Please enter the author:");
						scanf("%s",au);
						BookArray find_book_by_author (au);
						BookArray *m=h;
						while(m->next!=NULL)
							{
							printf("%d %s %s %d %d",m->array->id,m->array->title,m->array->authors,m->array->year,m->array->copies);
							m=m->next;
							}
						continue;
					case 3:
						printf("Please enter the year:");
						scanf("%d",y);
						BookArray find_book_by_year (y);
						BookArray *n=h;
						while(n->next!=NULL)
							{
							printf("%d %s %s %d %d",n->array->id,n->array->title,n->array->authors,n->array->year,n->array->copies);
							n=n->next;
							}
						continue;
					case 4:
						break;
				}
				continue;
			case 4:
				{
				Book *p=head;
				while(p->next!=NULL);
				{
					printf("%d %s %s %d %d",p->id,p->title,p->authors,p->year,p->copies);
					p=p->next;
				}
				continue;
				}
			case 5: 
			return 0;
			default:
      		printf("Illegal input!\n");
      		break;
	}
	}
}
