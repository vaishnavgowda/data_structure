#include<stdlib.h>
#include<stdio.h>

struct node
{
int data;
 struct node *left;
 struct node *right;
};
typedef struct node *Node;

Node getnode()
{
 Node x;
 x=(Node) malloc (sizeof(Node));
 if(x!=NULL)
 return x;
 else
 {
 printf("Memory is not allocated");
 exit(0);
 }
}
Node insert_left(Node first,int item)
{
 Node temp;
 temp=getnode();
 temp->data=item;
 temp->right=NULL;
 temp->left=NULL;
 if (first==NULL)
 return temp;
 else
 {
  temp->right=first;
  first->left=temp;
  first=temp;
  return first;
 }
}
Node delete(Node first,int val)
{
 int value=val;
 Node temp,prev,voi;
 temp=first;
 prev=NULL;
  while(temp->right!=NULL&&temp->data!=value)
  {
   prev=temp;
   temp=temp->right;
   
   }
   if(temp->data==value)
   {if (temp==first)
    {temp=temp->right;
     first=temp;
     }
     else
     {
     
    voi=temp->right;
    voi->left=prev;
    prev->right=voi;
    free(temp);
    }
    }
    else
    {
     printf("value not found");
     }
     return first;
    }
   void display(Node first)
{
Node temp;
 if(first==NULL)
 {
 printf("list is empty\n");
 }
 else
 {
 temp=first;
 printf("Element in the list: ");
 while(temp!=NULL)
 {
 printf("%d ",temp->data);
 temp=temp->right;
 }
 printf("\n");
 }
}
int main()
{
 Node first=NULL;
 int ch,value,pos;
 while(1)
{
printf("1.Insert \n");
printf("2.delete\n");
printf("3.display\n");
printf("4.Exit\n");
scanf("%d",&ch);
 switch(ch)
 {
 case 1: printf("Enter the element to be inserted: ");
 scanf("%d",&value);
 first=insert_left(first,value);
 break;
 case 2: printf("enter the value to be deleted: ");
 scanf("%d",&value);
 first=delete(first,value);
 break;
 case 3: display(first);
 break;
 case 4: exit(0);
 default: printf("Invalid choice\n");
 }
 }
 
 }

