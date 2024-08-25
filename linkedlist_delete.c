//delete operation in linked list

#include<stdio.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next;
};
struct node*s;
struct node *delete_beg(struct node*s);
struct node *delete_after(struct node*s);
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
	
	//delete after any data program
	struct node *delete_after(struct node*s);
    {
		int key;
    struct node *r,*first;
    first=s;
	printf("enter the data you want to delete\n");
	scanf("%d",&key);
	while(s->data!=key)
	{ 
	    r=s;
		s=s->next;
	}
	r->next=s->next;
	free(s);
	s=first;
    }
    
    printf("list of new data are:\n");
    struct node *delete_beg(struct node *s);
    struct node *delete_after(struct node *s);
    while(s!=NULL)
	{
	printf("%d\n",s->data);
	s=s->next;
	}
	getch();
}
