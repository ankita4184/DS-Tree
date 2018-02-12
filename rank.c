#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
    int n_left;
};
struct node* insert(struct node* root, int j)
{
    if(root == NULL)
    {
        struct node* a = (struct node*)malloc(sizeof(struct node));
        a->data = j;
        a->left = NULL;
        a->right = NULL;
        a->n_left = 0;
        return a;
    }
    else if(root->data > j)
    {
        root->left = insert(root->left, j);
        root->n_left++;
    }
    else 
    {
        root->right = insert(root->right, j);
    }

    return root;
} 
struct node* delete(struct node* root, int j)
{
    if(root->data == j)
    {
        return root->right; //wrong
    }
    else if(root->data > j)
    {
        root->left = delete(root->left, j);
        root->n_left--;
    }
    else
    {
        root->right = delete(root->right, j);
    }
    return root;
}

int rank1(struct node* root, int j)
{
    int rank;
    if(root == NULL)
        return 0;
    else if(root->data > j) // traverse left side
    {
        rank = rank1(root->left, j) - 1;
    }
    else if(root->data < j) // traverse right side
    {
        rank = root->n_left + rank1(root->right, j);
    }
    else if(root->data == j) // found the element
    {
        rank = root->n_left;
    }
    return (rank + 1);
} 
int main()
{
    struct node *root = NULL;
    int j;
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &j); // insert root values
        root = insert(root, j);
    }
    root = delete(root, 11);
    root = delete(root, 4);
    while(j != -1)
    {
        scanf("%d", &j); //insert key whose rank to calculate.
        printf("\t%d\n", rank1(root, j));
    }
    return 0;
}
