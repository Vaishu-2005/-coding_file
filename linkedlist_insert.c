#include<stdio.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next;
};
struct node*s;
struct node *insert_beg(struct node*s);
struct node *insert_after(struct node*s);
void main()
{
	char ch;
	struct node *p,*q;
	p=(struct node*)malloc(sizeof(struct node));
	printf("enter the value of first node\n");
	scanf("%d",&p->data);
	s=p;
	do
	{
		q=(struct node*)malloc(sizeof(struct node));
		printf("enter the value of next node\n");
		scanf("%d",&q->data);
		p->next=q;
		p=q;
		printf("press 'Y'/'N' for more node\n");
	    ch=getch();
	}while(ch=='Y'||ch=='y');
	p->next=NULL;
	
	//insert at beginning program
	struct node*insert_beg(struct node*s);
	{
	struct node*r;
	r=(struct node*)malloc(sizeof(struct node));
	printf("enter the value of new node at the beginning\n");
	scanf("%d",&r->data);
	r->next=s;
	s=r;
    }
	
	//inset after any data program
	struct node *insert_before(struct node*s);
	{
		int key;
    struct node *r,*q,*first;
    first=s;
	printf("after which data do you want to insert the element\n");
	scanf("%d",&key);
    r=(struct node*)malloc(sizeof(struct node));
	printf("enter the value of new node\n");
	scanf("%d",&r->data);
	while(s->data!=key)
	{ 
		s=s->next;
	}
	if(s->data==key)
	{
		q=s->next;
		s->next=r;
		r->next=q;
		s=first;
	}
    }
    printf("list of new data are:\n");n
    struct node *insert_beg(struct node *s);
    struct node *insert_after(struct node *s);
    while(s!=NULL)
	{
	printf("%d\n",s->data);
	s=s->next;
	}
	getch();
}
