#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node* ins(struct node *r, int i)
{
	if(r == NULL)
	{
		struct node *a = (struct node*)malloc(sizeof(struct node));
		(*a).data = i;
		(*a).left = NULL;
	    	(*a).right = NULL;	
		return a;
	}
	else if((*r).data == i)
	{
		(*r).data = i;
		return r;
	}
	else if((*r).data > i)
	{
		(*r).left = ins((*r).left, i);
	}
	else
	{
		(*r).right = ins((*r).right, i);
	}
	return r;
}
void insert(struct node **r, int i)
{
	*r = ins(*r, i);
}
int minimum(struct node *r)
{
	struct node *a = r;
	int t;
	while(a != NULL )
	{
		t = (*a).data;
		a = (*a).left;
	}
	return t;
}	
int maximum(struct node *r)
{
	struct node *a = r;
	int t;
	while(a != NULL)
	{
		t = (*a).data;
		a = (*a).right;	
	}
	return t;
}
int main()
{
	struct node *root = NULL;
	int i,k;
	for(i = 0; i < 5; i++)
	{
		scanf("%d", &k);
		insert(&root, k);
	}
	printf("%d\n",minimum(root));
	printf("%d\n",maximum(root));	
}
