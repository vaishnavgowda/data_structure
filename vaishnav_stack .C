

#include <stdio.h>
#include<stdlib.h>
#define max 6
 int top=-1,sta[max];
 void push();
 void pop();
 void disp();

 void main()
 {
      int ch;
      do
      {
	  printf(" \n STACK MENU \n");
	  printf(" \n ENTER 1 FOR PUSH, 2 FOR POP, 3 FOR DISPLAY 4 for exit \n");
	  scanf("%d",&ch);
	  switch(ch)
	  {
		case 1: push();
			break;
		case 2: pop();
			break;
		case 3: disp();
			break;
	    default: printf("\n WRONG CHOICE\n");exit(0);
	  }
      }while(1);
 }


 void push()
 {   int val;
     if(top==max-1)
     {
	 printf("\n STACK OVERFLOW!! \n");

     }
     else
     {
       printf("\n ENTER ELEMENT TO INSERT \n");
       scanf("%d",&val);
       top=top+1;
       sta[top]=val;

     }
 }
 void pop()
 {
     if(top<0)
     {printf(" \n STACK IS EMPTY \n");}
     else
     {
	 top=top-1;

     }
}
void disp()
{
	int i;
     if(top<0)
     {printf(" \n STACK IS EMPTY \n");}
     else
     {
	 printf(" \n THE STACK IS ... \n");
	 for(i=0;i<max;i++)
	 {printf("  %d \n",sta[i]);}
     }
}