#include<stdio.h>
void main()
{
    int a[5],i,found=0,item,pos=0;
    printf("enter the array elements\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the element you want to search\n");
    scanf("%d",&item);
    for(i=0;i<5;i++)
    {
   if(item==a[i])
    {
    pos=i;
    found=1;
    printf("%d is found at %d position\n",item,pos+1);
    }
    }
    if(found==0)
    {
        printf("item not found\n");
    }
   
}
