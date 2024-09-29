#include <stdio.h>
#define MAX 100
int stack1[MAX],Top = -1; 
int push();
int pop();
int print();  
int main()
 {
    int choice, c=0, d=0;
    char ch, print;
    printf("enter 1 for push\n");
    printf("enter 2 for pop\n");
    printf("enter 3 for exit\n");
        do
		{
		    printf("enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
		    {
                case 1:
                    push();
                    c++;
                    break;
                case 2:
                    pop();
                    d++;
                    break;
                case 3:
                    Exit();
                    break;
                default:
                    printf("wrong input\n");
            }
            printf("enter y to continue\n");
		    scanf(" %c",&ch);
    
	    }while (ch=='y');
	printf("enter 'p' to print elements\n");
	scanf(" %c",&print);
	while(print=='p')
	{
		for(Top=0;Top<c-d;Top++)
		{
			printf("%d\t",stack1[Top+1]);
		}
		break;
	}
}
int push() 
{
	int num;
    if (Top == MAX-1) 
	{
        printf("stack overflow\n");
        Exit();
    }
    else
    {
    printf("enter the number you want to push: ");
    scanf("%d", &num);
    Top=Top+1;
    stack1[Top] = num; 
	}     
}
int pop()
 {
 	int y, i;
    if (Top == -1)
	{
        printf("stack underflow\n");
        Exit();
    }
	else
	{
	 y = stack1[Top];    
    Top=Top-1;
    printf("%d removed\n",y);
    }
}
int Exit()
{
	Exit();
}
