#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char data[20];
	int frequency;
    struct node *left;
    struct node *right;
};
int f = 0;
char data[20];
struct node* ins(struct node* root, char k[20])
{
	if(root == NULL)
	{
		struct node *a = (struct node*)malloc(sizeof(struct node));
		strcpy(a->data, k);
		a->left = NULL;
		a->right = NULL;
		a->frequency = 1;
		return a;
	}
	else if(strcmp(root->data, k) == 0)
		{
			root->frequency++;
			if(root->frequency > f)
			{
				f = root->frequency;
  				strcpy(data,root->data);
			}
		}
	else if(k > root->data)
			root->right = ins(root->right, k);
	else
			root->left = ins(root->left, k);
	return root;
}
void insert(struct node** root, char k[20])
{
		*root = ins(*root, k);
}
int main()
{
    struct node *root = NULL;
    char k[20];
    int i;
	for(i = 0; i < 10000; i++)
	{
		scanf("%s",k);
		insert(&root, k);
	}
	printf("%d   %s\n",f,data);
}
