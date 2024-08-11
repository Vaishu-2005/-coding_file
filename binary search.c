#include<stdio.h>
void main()
{
	int a[100],n,i,num,low,mid,high;
	printf("enter the no of elements\n");
	scanf("%d",&n);
	printf("enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the number you want to search\n");
	scanf("%d",&num);
	low=0;
	mid=(low+high)/2;
	high=n;
	for(i=0;i<n;i++)
	{
	  if(num==a[mid])
	  {
	  	printf("%d element is found at %d position\n",num,mid);
	  	break;
	  }
	 if(num<a[mid])
	  {
	  	high=mid-1; 
	  }
	  if(num>a[mid])
	  {
	  	low=mid+1;
	  }
	  mid=(low+high)/2;
	}
}
