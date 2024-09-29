#include<stdio.h>
#include<malloc.h>
struct node
{
  int data;
  struct node*next;
};
struct node *top=NULL;
void push(int x)
{
  struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=x;
  new->next=top;
  top=new;
}
void pop()
{
	struct node*t;
	if(top==NULL)
	{
		printf("stack underflow");
	}
	else
	{
		t=top;
		top=top->next;
		free(t);
		t=NULL;
	}
}
void print()
{
	struct node*s =top;
	printf("new stack list is:\n");
	while(s!=NULL)
	{
	  printf("%d\n",s->data);
	  s=s->next;	
	} 
}
int main()
{
	int choice,value,new;
	char ch;
	printf("enter 1 for push\n");
	printf("enter 2 for pop\n");
	do
	{
		printf("enter your choice:\n");
	    scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter the value you want to push:\n");
			        scanf("%d",&value);
			        push(value);
			        break;
		    case 2:pop();
		            break;
		    default:printf("wrong input\n");
		           break;
		}
		print();
		printf("enter 'y'/'n'to continue\n");
		ch=getch();
	}while(ch=='y'||ch=='Y');
	getch();
    return 0;
}
