#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node*next;
};
struct node*newnode,*head=0;

void push() {
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter the data");
scanf("%d",&newnode->data);
newnode->next=head;
head=newnode;
printf("\n%d is pushed into the stack",head->data);
}
void pop() {
struct node*temp;
if(head==0)
{printf("\nstack is empty ");
return;
}
else
{
temp=head;
printf("the delete data is %d",temp->data);
head=head->next;
free(temp);
}
}
void peek()
{
if(head==0)
{
printf("\nstack is empty");
return;
}
else
printf("last element is %d" ,head->data);
}
void display()
{
struct node* temp;
if(head==0)
{
printf("stack is empty");
return;
}
else
{
temp=head;
while(temp!=0)
{
printf("%d",temp->data);
temp=temp->next;
}
} } 
int main()
{
int opt;
do
{
printf("\n1)PUSH\n");
        printf("2)POP\n");
        printf("3)PEEK\n");
        printf("4)DISPLAY\n");
        printf("5)QUIET");
        printf("\nchoose your option : \n");
        scanf("%d",&opt);
        switch(opt)
        {
          case 1:push();
                break;
          case 2:pop();
                break;
          case 3:peek();
                break;
          case 4:display();
                break;
          case 5:exit(0);
          default: printf("invalid option\n");  
      }
    }while(1);
  }
          
          
          
