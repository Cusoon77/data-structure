#include<stdio.h>
int main()
{
int a[100],i,l,pos,n;
printf("Enter the array limit\n");
scanf("%d",&l);
printf("Enter the arrray elements\n");  
for (i=0;i<l;i++)
{
scanf("%d",&a[i]);
}
printf("inserted Array\n");
for(i=0;i<l;i++)
{
printf("%d, ",a[i]);
}
printf("\n");
printf("Enter the element position\n");
scanf("%d",&pos);
printf("Enter the element\n");
scanf("%d",&n);
for (i=l;i>=pos;i--)
{
a[i]=a[i-1];
}
a[pos]=n;
l++;
printf("New element inserted array\n");
for (i=0;i<l;i++)
{
printf("%d, ",a[i]);
}
return (0);
}

