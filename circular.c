#include<stdio.h>

#include<string.h>
#include<stdlib.h>
#define size 5
void enqueue(int[],int *,int *);
void dequeue(int [],int *,int *);
void display(int[],int*,int *);
void main()
{
int choice,queue[size],front=-1,rear=-1;

do
{
printf("enter the choice :\n 1 .insert \n 2.delete\n 3  display \n any other number to exit\n ");
scanf("%d",&choice);
switch(choice)
{
 case 1:
 enqueue(queue,&front,&rear);
 break;
 case 2:
 dequeue(queue,&front,&rear);
 break;
 case 3 :
 display(queue,&front,&rear);
 break;
}
}while(choice==1||choice==2||choice==3);


}
void enqueue(int queue[size],int*front,int *rear)
{
int ele;
if (((*rear)==size-1 && (*front)==0)||((*rear)==(*front)-1))
printf ("queue overflow\n");
else
{
if (*rear==-1)
*front=0,*rear=0 ;
else if((*rear)==(size-1))
(*rear)=0;
else
(*rear)++;
printf("enter the element to be inserted");
scanf("%d",&ele);
queue[(*rear)]=ele;
printf("the element inserted is %d\n",ele);
}
}
void dequeue(int queue[size],int *front, int *rear)
{
if (*front==-1)
printf ("empty\n");
else
{
printf("the deleted element is %d\n",queue[*front]);
if(*front==*rear)
*front=-1,*rear=-1;
else if(*front==size-1)
*front=0;
else
(*front)++;
}
}

void display(int queue[size],int*front,int *rear)
{
int i,j;
if ((*rear==-1)&&(*front==-1))
printf ("the queue is empty\n");
else if (*front>*rear)
{
for (i=*front;i< size;i++)
printf("%d\n",queue[i]);
for(j=0;j<=(*rear);j++)
printf("%d\n",queue[j]);
}
else
{
for(i=*front;i<=*rear;i++)
printf("%d\n",queue[i]);
}
}
