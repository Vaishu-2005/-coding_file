#include<stdio.h>
int main()
{
    int a[100],n,i,j,num,temp;
    printf("enter the no of element\n");
    scanf("%d",&n);
    printf("enter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
             temp=a[i];
			 a[i]=a[j];
			 a[j]=temp;   
            }
        }
	}
	printf("sorted array elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	
		return 0;
 }


