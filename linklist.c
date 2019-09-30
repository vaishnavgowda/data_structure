#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
	};
	
typedef struct node* node;

node get_node();
node ins_f(node first, int val);
node ins_b(node first, int val);
node ins_any_position(node first , int val , int pos);
node del_front(node first);
node del_back(node first);
node del_any_pos(node first , int pos);
void display(node first);

node first = NULL;

int main(){
	int i, x, val,pos;
	
	while(x != 8){
		printf("\n1: Enter val from front\n");
		printf("2: Enter val from back\n");
                printf("3: Enter val at any given position\n");
                printf("4: Delete from front\n");
                printf("5: Delete from back\n"); 
                printf("6: Delete at any given position\n");
		printf("7: Display\n");
		printf("8: Exit\n");
		scanf("%d", &x);
			switch(x){
			case 1:
				printf("\nEnter value from front: \n");
				scanf("%d", &val);
				first = ins_f(first, val);
				break;
				
			case 2:
				printf("\nEnter value from back: \n");
				scanf("%d", &val);
				first = ins_b(first, val);
				break;

                        case 3: printf("\nEnter the value to be inserted and position\n");
                                scanf("%d%d",&val,&pos);
                                first = ins_any_position(first , val , pos);
                                break;
                   
                        case 4: first = del_front(first);
                                break;
   
                        case 5: first = del_back(first);
                                break;
 
                        case 6: printf("\nEnter the position to be deleted\n");
                                scanf("%d",&pos);
                                first = del_any_pos(first , pos); 
                                break;
				
			case 7: printf("\nThe elements in the list are:\n");
				display(first);
				break;
                                
			}
		}
	}
		
node get_node(){
	node temp;
	temp = (node)malloc(sizeof(struct node));
	temp->next = NULL;
	return temp;
	}
	
	

node ins_f(node first, int val){
	node temp;
	if(first == NULL){
		first = get_node();
		first-> val = val;
		}
	else{
		temp = get_node();
		temp->val = val;
		temp->next = first;
		first = temp;
		
		}
	return first;	
	}

node ins_b(node first, int val){
	node temp, curr;
	if(first == NULL){
		first = get_node();
		first-> val = val;
		}
	else{
		curr  = first;
		while(curr->next != NULL){
			curr = curr->next;
			}
				 
		temp = get_node();
		temp->val = val;
		curr->next = temp;
		}
	return first;
	}

node ins_any_position(node first , int val , int pos)
{
  int count = 1;
  node temp,cur,prev;
  temp = get_node();
  temp->val = val;
  temp->next = NULL;
  if(first == NULL && pos == 1)
  {
    return temp;
  }
  if(first == NULL && pos!=1)
  {
    printf("Invalid position");
  }
  cur = first;
  prev = NULL;
  while(cur->next != NULL && count != pos)
  {
    prev = cur;
    cur = cur->next;
    count++;
  }
  if(count == pos)
  {
    prev->next = temp;
    temp->next = cur;
    return first;
  }
  else
  {
    printf("\nNot a valid position\n");
  }
} 

node del_front(node first)
{
  node temp;
  if(first == NULL)
  {
    printf("\nList is empty\n");
  }
  temp = first;
  printf("\nDeleted element is %d",temp->val);
  temp = temp->next;
  free(first);
  first = temp;
  return first;
}

node del_back(node first)
{
  node cur,prev;
  if(first == NULL)
  {
    printf("\nList is empty\n");
  }
  cur = first;
  prev = NULL;
  while(cur->next != NULL)
  {
    prev = cur;
    cur = cur->next;
  }
  prev->next = NULL;
  free(cur);
  return first;
}

node del_any_pos(node first , int pos)
{
  node cur,prev;
  int count = 1;
  if(first == NULL)
  {
    printf("\nList is empty\n");
  }
  if(first->next == NULL && pos == 1)
  {
    printf("\nThe deleted element is %d\n\n",first->val);
    free(first);
    return NULL;
  }
  if(first == NULL && pos!=1)
  {
    printf("\nInvalid position\n");
  }
  cur = first;
  prev = NULL;
  while(cur->next != NULL && count != pos)
  {
    prev = cur;
    cur = cur->next;
    count++;
  }
  if(count == pos)
  {
    prev->next = cur->next;
    printf("\nThe deleted element is %d\n",cur->val);
    free(cur);
  }
  else
  {
    printf("\nNot a valid position\n");
  }
  return first;
}
  
	
void display(node first){
	node curr;
	curr = first;
	while(curr != NULL){
		printf("%d\n", curr->val);
		curr = curr->next;
		}
	}
