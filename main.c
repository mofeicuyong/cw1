#include "book_management.c"
#include "student.c"
int main()
{
	Book book;
	printf("Welcome to use this system:\n");
	Student* hh,*tt;
	hh=tt=(Student*)malloc(sizeof(Student));
	hh->next=NULL;
	Book* head,*tail;
	head=(Book*)malloc(sizeof(Book));
	head->next=NULL;
	Book* h,*t;
	h=(Book*)malloc(sizeof(Book));
	h->next=NULL;
	Book* hhh;
	hhh=(Book*)malloc(sizeof(Book));
	hhh->next=NULL;
	int a;
	int time=0;
	int kk;
	BookArray x;
	while(1)
	{
		menu1();
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				register_id(hh);
				continue;
			case 2:
				kk=log_in(hh);
				if(kk==-2)
				{
					time=0;
					while(time==0)
					{
						menu2();
						scanf("%d",&a);
						switch(a)
						{
							case 1:
								add_book(head);
								continue;
							case 2:
								remove_book(head);
								continue;
							case 3:
								
								search(head,h);
								continue;
							case 4:
								{
								Book *p=head;
								while(p->next!=NULL)
								{
									p=p->next;
									printf("%d %s %s %d %d",p->id,p->title,p->authors,p->year,p->copies);
									printf("\n");
								}
								continue;
								}
							case 5:
								time=1;
								break;
							default:
      							printf("Illegal input!\n");
      							continue;
							
						}
					}
				}
				else if(kk!=-2&&kk!=-1)
				{
					time=0;
					while(time==0)
					{
					menu4();
					scanf("%d",&a);
					switch(a)
					{
						case 1:
							Borrow_book(head,kk,hh,hhh);
							continue;
						case 2:
							return_book(head,kk,hh,hhh);
							continue;
						case 3:
							search(head,h);
							continue;
						case 4:
							{
							Book *p=head;
							while(p->next!=NULL)
							{
								p=p->next;
								printf("%d %s %s %d %d",p->id,p->title,p->authors,p->year,p->copies);
								printf("\n");
							}
							continue;
							}
						case 5:
							time=1;
							continue;
						default:
      						printf("Illegal input!\n");
      						continue;
							
					}
					}
				}
				continue;
			case 3: 
				search(head,h);
				continue;
			case 4:
				{
					Book *p=head;
					while(p->next!=NULL)
					{
						p=p->next;
						printf("%d %s %s %d %d",p->id,p->title,p->authors,p->year,p->copies);
						printf("\n");
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
