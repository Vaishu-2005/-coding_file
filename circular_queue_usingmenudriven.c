#include<stdio.h>
#define max 5
int myqueue[max];
int r=-1,f=-1;
void enqueue();
void dequeue();
void display();
int main()
{
	int choice;
	printf("enter 1 for insert\n");
	printf("enter 2 for delete\n");
	printf("enter 3 for print\n");
	printf("enter 4 for exit\n");
	do
	{
		printf("enter your choice: \n");
	    scanf("%d",&choice);
		switch(choice)
		{
			case 1:enqueue();
			       break;
		    case 2:dequeue();
		           break;
		    case 3:display();
		           break;
		    default:printf("invalid input");
		            break;
		}
	}while(choice!=4);
	return 0;
}
void enqueue()
{
	int item;
	printf("enter the value you want to insert\n");
	scanf("%d",&item);
	if( (f==0 && r==max-1) || (f==r+1) )
    {
    	printf("queue overflow\n");
    	return;
	}
	if(f==-1)
	{
		f=0;
		r=0;
	}
	else
	{
		r=r+1;
	}
	myqueue[r]=item;
	printf("inserted %d\n",item);
}
void dequeue()
{
	int item;
	if(f==-1 && f>r )
	{
		printf("queue underflow\n");
		return;
	}
	item=myqueue[f];
	if(f==r)
	{
		f=-1;
		r=-1;
	}
	else if(f==max-1)
	{
		f=0;
	}
	else
	{
		f=f+1;
	}
    printf("delete %d\n",item);
}
void display()
{
	int i;
	printf("queue element: ");
	for(i=f ; i<=r ; i++)
	{
		printf("%d  ",myqueue[i]);
	}
    printf("\n");
}
