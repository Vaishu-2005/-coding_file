#include<stdio.h>
#define max 10
int myqueue[max];
int f=-1, r=-1;
void dequeue();
void enqueue();
void print();
int main()
{
    int choice;
    printf("enter 1 for insert\n");
    printf("enter 2 for delete\n");
    printf("enter 3 for print\n");
    printf("enter 4 for exit\n");
	do
	{
	  printf("enter your choice : \n");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	    case 1:enqueue();
	            break;
	    case 2:dequeue();
	            break;
	    case 3:print();
	            break;
	    default:printf("invalid input\n");
	            break;              
	  }
	} while(choice!=4 );
return 0;
}
void enqueue()
{
    int num;
    printf("enter the number you want insert : \n");
    scanf("%d",&num);
    if(r==max-1)
    {
        printf("queue overflow\n");
        return;
    }
    if(f==-1&&r==-1)
    {
        f=0;
        r=0;
    }
    else
    {
        r=r+1;
    }
    myqueue[r]=num;
}
void dequeue()
{
    if(f==-1||f>r)
    {
        printf("queue underflow\n");
        return;
    }
    if(f>r)
    {
      f=-1;
      r=-1;
    }
    else
    {
	  printf("deleted element is : %d\n ",myqueue[f]);
	  f=f+1;
    }
}
void print()
{
    int  i;
    if(f==-1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("queue list is: \n");
        for(i=f;i<=r;i++)
        {
            printf("%d\n",myqueue[i]);
        }
    }
}
