#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
  int data;
  struct node *next;
}*Node;

Node getnode()
{
  Node p;
  p=(Node) malloc (sizeof(Node));
  if(p!=NULL)
    return p;
  else
    {
      printf("Memory is not allocated");
      exit(0);
    }
}

Node insert_front(Node head,int item)
{
  Node p;
  p=getnode();
  p->data=item;
  p->next=head;
  head=p;
  return head;
}

Node insert_end(Node head,int item)
{
  Node p,q;
  q=getnode();
  q->data=item;
  q->next=NULL;
  if(head==NULL)
     return q;
  p=head;
  while(p->next!=NULL)
     p=p->next;
  p->next=q;
  return head;
}


void display(Node head)
{
  Node p;
  if(head==NULL)
    {
      printf("list is empty\n");
    }
  else
    {
      p=head;
      printf("Element in the list: ");
      while(p!=NULL)
        {
          printf("%d ",p->data);
          p=p->next;
         }
      printf("\n");
     }
}

int main()
{
  Node head=NULL;
  int option,ele,value,pos;
  do
   {
     printf("\n1)Insert Front\n2)Insert End\n3)Display\n4)Exit\n");
     printf("Enter your choice: "); 
     scanf("%d",&option);
     switch(option)
       {
         case 1: printf("Enter the element to be inserted: ");
                 scanf("%d",&ele);
                 head=insert_front(head,ele);
                 break;
         case 2: printf("Enter the element to be inserted: ");
                 scanf("%d",&ele);
                 head=insert_end(head,ele);
                 break;
         case 3: display(head);
                 break;
         case 4: break;
         default: printf("Invalid choice\n");
       }
    }while(option!=5);
  return 0;
}
