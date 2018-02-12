#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}tree;
tree* add_in(tree* t, int data)
{
    if(t == NULL)
    {
        tree* t1 = (tree*)malloc(sizeof(tree));
        t1->data = data;
        t1->left = NULL; t1->right = NULL;
        return t1;
    }
    else if(t->data < data)
        t->right = add_in(t->right, data);
    else if(t->data > data)
        t->left = add_in(t->left, data);
    return t;
}
void printleft(tree* r)
{
    tree* root = r;
    if(root == NULL)
        return;
    if(root->left != NULL || root->right != NULL)
    printf(" %d ",root->data);
    printleft(root->left);
}
void printright(tree* r)
{
    tree* root = r;
    if(root == NULL)
        return;
     printright(root->right);

    if(root->left != NULL || root->right != NULL)
       printf(" %d ", root->data);
}
void printleave(tree *r)
{
    if(r == NULL)
        return;
    printleave(r->left);
    if(r->left == NULL && r->right == NULL)
        printf(" %d ",r->data);
    printleave(r->right);


}
void circum(tree* root)
{
   if(root != NULL)
    {
        printleft(root);
        printleave(root->left);
        printleave(root->right);
        printright(root->right);
    }
      
}
int main()
{
    tree* root = NULL;
    root = add_in(root, 5);
    root = add_in(root, 3);
    root = add_in(root, 7);
    root = add_in(root, 2);
    root = add_in(root, 4);
    root = add_in(root, 6);
    root = add_in(root, 8);
    circum(root);
    return 0;
}
