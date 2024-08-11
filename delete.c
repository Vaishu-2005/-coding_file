#include<stdio.h>
void main()
{
	int a[100],n,i,index,;
	printf("enter the no of element\n");
	scanf("%d",&n);
	printf("enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("which index you want to delete\n");
	scanf("%d",&index);
	for(i=index;i<n;i++)
	{
	a[i]=a[i+1];
	}
	printf("new array:\n");
	for(i=0;i<n-1;i++)
	{
		printf("%d\n",a[i]);
	}
}
