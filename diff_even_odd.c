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
}stack;
stack* head = NULL;
void push(stack **head, tree* t1) //add at front 
{
    stack* a = (stack*)malloc(sizeof(stack));
    a->t = t1;
    if(*head == NULL)
    {
         *head = a;
         a->next = NULL;
    }
    else
    {
        a->next = *head;
        *head = a; 
    }
}
tree* pop(stack **head) //return first tree
{
    stack* b = *head;
    (*head) = (*head)->next;
    return b->t;
}
int isEmpty(stack *head)
{
    if(head == NULL)
        return 0;
    return 1;
}
tree* add_in(tree* root, int data)
{
    if(root == NULL)
    {
        tree* t1 = (tree*)malloc(sizeof(tree));
        t1->data = data;
        t1->left = NULL;    t1->right = NULL;
        return t1;
    }
    else if(root->data > data)
        root->left = add_in(root->left, data);
    else if(root->data < data)
        root->right = add_in(root->right, data);
    return root;
}
void evenodd(tree* root)
{
    int i = 0, sume = 0, sumo = 0;
    stack *head1 = NULL;
    push(&head1, root);
    while(isEmpty(head1))
    {
        stack *head2 = NULL;
            while(isEmpty(head1))
            {
                tree *b = pop(&head1);
                if(i == 0)
                    { sumo += b->data; }
                else
                  {  sume += b->data; }
                if(b->left != NULL)
                    push(&head2, b->left);
                if(b->right != NULL)
                    push(&head2, b->right);
            }
       head1 = head2;
        i = i ^ 1;
    }
    printf(" %d ", sumo - sume);
}
int main()
{
    tree* root = NULL;
    root = add_in(root, 5);
    root = add_in(root, 3);
    root = add_in(root, 4);
    root = add_in(root, 2);
    root = add_in(root, 7);
    root = add_in(root, 6);
    evenodd(root);
    return 0;
}
