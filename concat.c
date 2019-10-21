#include<stdlib.h>
#include<stdio.h>

struct node
{
	int data;
 struct node *next;
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
Node insert_front(Node first,int item)
{
 Node temp;
 temp=getnode();
 temp->data=item;
 temp->next=first;
 first=temp;
 return first;
}

Node insert_end(Node first,int item)
{
 Node temp,x;
 x=getnode();
 x->data=item;
 x->next=NULL;
 if(first==NULL)
 return x;
 temp=first;
 while(temp->next!=NULL)
 temp=temp->next;
 temp->next=x;
 return first;
}
Node delete_beg(Node first)
{
 Node temp;
 if(first==NULL)
 printf("List is empty\n");
 else
 {
 temp=first;
 printf("Item deleted is %d\n",temp->data);
 temp=temp->next;
 free(first);
 }
 return temp;
 
}
 
Node delete_end(Node first)
{
	Node curr,prev;
 if(first==NULL)
 printf("List is empty\n");
 else
 {
 curr=first;
 prev=NULL;
 while(curr->next!=NULL)
 {
 prev=curr;
 curr=curr->next;
 }
 printf("Item deleted is %d\n",curr->data);
 prev->next=NULL;
 free(curr);
 }
 return first;
}
Node concatinate(Node first1,Node first2)
{
 Node temp;
 if (first1==NULL)
 return first2;
 else if(first2==NULL)
 return first1;
 else{
   temp=first1;
    while(temp->next!=NULL)
   {
     temp=temp->next;
    }
    temp->next=first2;
    return first1;
  }
 }  
 Node sort(Node first){
	int swapped = -1;
	Node curr, last, temp;
	if(first == NULL){
		printf("Linked list is empty");
		return first;
	}
	else{
		
		last = NULL;
		while(swapped != 0){
			swapped = 0;
			curr = first;
			while(curr->next != last){
				if(curr->data > (curr->next)->data){
					temp->data = curr->data; 
					curr->data = (curr->next)->data;
					(curr->next)->data = temp->data;
					}
				swapped = 1;
				curr = curr->next;
				}
			last = curr;
			}
		
		}
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
 temp=temp->next;
 }
 printf("\n");
 }
}
int main()
{
 Node first1=NULL;
 Node first2=NULL;
 int ch,value;
 while(1)
	{
	printf("1.Insert the node for list 1 at the front\n");
	printf("2.Insert the node for list 1 at end\n");
	printf("3.Insert the node for list 2 at the front\n");
	printf("4.Insert the node for list 2 at end\n");
	printf("5.Delete the node for list 1 in front\n");
	printf("6.Delete  the node for list 1 in end\n");
	printf("7.Delete the node for list 2 in front\n");
	printf("8.Delete  the node for list 2 in end\n");
	printf("9.concatinate the list\n");
	printf("10.sort the concatinated list\n");
	printf("11.Display the full list\n");
	printf("12.Exit\n");
	scanf("%d",&ch);
 switch(ch)
 {
 case 1: printf("Enter the element to be inserted: ");
 scanf("%d",&value);
 first1=insert_front(first1,value);
 break;
 case 2: printf("Enter the element to be inserted: ");
 scanf("%d",&value);
 first1=insert_end(first1,value);
 break;
 case 3: printf("Enter the element to be inserted: ");
 scanf("%d",&value);
 first2=insert_front(first2,value);
 break;
 case 4: printf("Enter the element to be inserted: ");
 scanf("%d",&value);
 first2=insert_end(first2,value);
 break;
 case 5: first1=delete_beg(first1);
 break;
 case 6: first1=delete_end(first1);
 break;
 case 7: first2=delete_beg(first2);
 break;
 case 8: first2=delete_end(first2);
 break;
 case 9:  first1=concatinate(first1,first2);
 break; 
 case 10: first1=sort(first1);
 break;
 case 11: display(first1);
 break;
 case 12: exit(0);
 default: printf("Invalid choice\n");
 }
 }
 return 0;
}
