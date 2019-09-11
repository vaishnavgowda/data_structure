#include<stdio.h>      
#include<string.h>
#include<stdlib.h>
#define size 3
void enqueue(int[],int *,int *);
void dequeue(int[],int *);
void display(int[],int*,int *);
void main()
{
int choice,queue[size],front=-1,rear=-1;
do
{
printf("enter the choice :\n 1 to insert element \n 2 to delete element \n 3 to display\n any other number to exit\n ");
scanf("%d",&choice);
switch(choice)
{
 case 1:
 enqueue(queue,&front,&rear);
 break;
 case 2:
 dequeue(queue,&front);
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
if ((*rear)==size-1) 
printf ("queue overflow");
else
{
if (*rear==-1)
*front=0,*rear=0 ;
else
(*rear)++;
printf ("enter the element to insert");
scanf("%d",&ele);
queue[(*rear)]=ele;

}
}
void dequeue(int queue[size],int *front)
{
int ele;
if ((*front)==-1)
printf ("queue is empty");
else
{
ele=queue[*front];
printf("the element deleted is %d",ele);
(*front)++;
}
}
void display(int queue[size],int*front,int *rear)
{
int new[size],i,count=0;
for (i=*front ;i<=*rear;i++)
{
        if (queue[i]%2==0 && queue[i]%3==0 &&queue[i]%4==0 &&queue[i]%5==0 &&queue[i]%6==0 &&queue[i]%7==0 &&queue[i]%8==0 &&queue[i]%9==0 &&queue[i]%10==0)
        {new[count]=queue[i];
        count++;}
}