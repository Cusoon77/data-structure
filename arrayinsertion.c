#include<stdio.h>
int main ()
{
int array[100],n,pos,item,i;
printf("enter number of element:");
scanf("%d",&n);
printf("enter %d element:\n" ,n);
for(i=0;i<n;i++)
{
scanf("%d",&array[i]);
}
printf("enter position to insert (in to %d): ",n);
scanf("%d",&pos);
printf("Enter value to insert:");
scanf("%d",&item);
for(i=n;i>=pos;i--)
{
array[i]=array[i-1];
}
array[pos-1]=item;
n++;
printf("array after insertion:\n");
for(i=0;i<n;i++)
{
printf("%d\t",array[i]);
}
return(0);
}
