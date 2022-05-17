#include <stdio.h>
#include <conio.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;
struct node *root;

int arr[20];
int i=0;

void bst()
{
	struct node *ptr,*ptr1,*ptr2;
	ptr = (node *)malloc(sizeof(node));
	printf("Enter the data : ");
	scanf("%d",&ptr->data);
	ptr->left = NULL;
	ptr->right = NULL;
	if(root==NULL)
	{
		root = ptr;
	}
	else
	{
		ptr1=root;
		while(ptr1!=NULL)
		{
			if(ptr->data < ptr1->data)
			{
				ptr2=ptr1;
				ptr1 = ptr1->left;
			}
			else
			{
				ptr2=ptr1;
				ptr1 = ptr1->right;
			}
		}
		if(ptr->data < ptr2->data)
		{
//			ptr->prev = ptr2;
			ptr2->left=ptr;
		}
		else
		{
//			ptr->prev = ptr2;
			ptr2->right = ptr;
		}
		
	}
}

void display(struct node *node)
{
	if(root == NULL)
	{
		printf("Empty Tree");
	}
	else
	{
		if(node->left !=NULL)
			display(node->left);
		arr[i]=node->data;
		i++;
		printf("\n%d",node->data);
		if(node->right !=NULL)
			display(node->right);
	}
	
	
	
}
void floor_ceil()
{
	node *ptr;
	int j,num;
	printf("Enter the number : ");
	scanf("%d",&num);
//	printf("Enter the number : %d",num);
//	for(j=0;j<i;j++)
//	{
//		printf("%d",arr[j]);
//	}
	for(j=0;j<i;j++)
	{
		if(arr[j]>=num)
			break;
	}
	if(arr[j]==num)
	{
		printf("The floor of %d  is %d, ceil of %d is %d",num,arr[j],num,arr[j]);
	}
	else if(j==0)
	{
		printf("The floor of %d does not exist, ceil of %d is %d",num,num,arr[j]);
	}
	else if(j==i)
	{
		printf("The floor of %d  is %d, ceil of %d does not exist",num,arr[j-1],num);
	}
	else
	{
		printf("The floor of %d  is %d, ceil of %d is %d",num,arr[j-1],num,arr[j]);
	}
}

void main()
{
	int ch;
	while(1)
	{
		printf("\n1. Construct the tree \n2. Display \n3. Floor and Ceil");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				bst();
				break;
			case 2:
				display(root);
				break;
			case 3:
				floor_ceil();
				break;
			default:
				printf("Wrong Input");
				
		}
	}
	
}
