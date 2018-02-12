#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}tree;
typedef struct node1{
    tree* t;
    struct node1* next;
}queue;
queue* head = NULL;
void push(tree* ti) //add at end of linked list
{
    queue* a = (queue*)malloc(sizeof(queue));
    a->t = ti;
    a->next = NULL;
    if(head == NULL)
    {
        head = a;
    }
    else
    {
        queue* b = head;
        while(b->next != NULL)
        {
            b = b->next;
        }
        b->next = a;
    }
}
queue* pop() //return the first element
{
    queue* a = head;
    head = head->next;
    return a;
}
int isEmpty()
{
    if(head == NULL)
        return 0;
    return 1;
}
tree* add_in(tree* root,int data)
{
    if(root == NULL)
    {
      tree* t = (tree*)malloc(sizeof(tree));
      t->data = data;
      t->left = NULL;
      t->right = NULL;
      return t;
    }
    else if(root->data > data)
    {
        root->left = add_in(root->left, data);
    }
    else if(root->data < data)
    {
        root->right = add_in(root->right, data);
    }
    return root;
}
void levelorder(tree* root)
{
    queue* b = NULL;
    push(root);
    while(isEmpty())
    {
        b = pop();
        printf("  %d  ",b->t->data);
        if(b->t->left != NULL)
            push(b->t->left);
        if(b->t->right != NULL)
            push(b->t->right);
    }
}
int main()
{
    tree* root = NULL;
    root = add_in(root, 5);
    root = add_in(root, 3);
    root = add_in(root, 4);
    root = add_in(root, 2);
    root = add_in(root, 7);
    root = add_in(root, 8);
    levelorder(root);
    return 0;
}
     
