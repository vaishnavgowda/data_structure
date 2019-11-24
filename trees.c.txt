#include<stdio.h>
#include<stdlib.h>
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
	x=(Node)malloc(sizeof(Node));
	return x;
}

Node create(Node curr,int item)
{
	if(curr==NULL)
	{
	curr=getnode();
	curr->data=item;
	curr->left=NULL;
	curr->right=NULL;
	}
	else
	{
	if(item<curr->data)
	curr->left=create(curr->left,item);
	else
	curr->right=create(curr->right,item);
	}
	return curr;
}

void inorder(Node root)
{
	Node r;
	r=root;
	if(r!=NULL)
	{
		inorder(r->left);
		printf("%d->",r->data);
		inorder(r->right);
	}
}

void preorder(Node root)
{
	Node r;
	r=root;
	if(r!=NULL)
	{
		printf("%d->",r->data);
		preorder(r->left);
		preorder(r->right);
	}
}
void postorder(Node root)
{
	Node r;
	r=root;
	if(r!=NULL)
	{
		postorder(r->left);
		postorder(r->right);
		printf("%d->",r->data);
	}
}
void main()
{
	Node root=NULL;
	int i,item,n;
	while(1)
	{
		printf("\n1.creating a binary search tree\n");
		printf("2.display in preoder\n");
		printf("3.display in inorder\n");
		printf("4.display in postorder\n");
		printf("5.exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			printf("enter 0 end\n");
			printf("enter data: ");
			scanf("%d",&item);
			while(item!=0)
			{
				root=create(root,item);
				printf("enter data: ");
				scanf("%d",&item);
			}
			break;
			case 2:
			printf("traversal in PREORDER:\n");
			preorder(root);
			break;
			case 3:
			printf("traversal in INORDER:\n");
			inorder(root);
			break;
			case 4:
			printf("traversal in POSTORDER:\n");
			postorder(root);
			break;
			case 5:
			exit(0);
		}
	}
}