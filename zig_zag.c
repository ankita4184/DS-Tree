#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}tree;
typedef struct node1{
    tree *t;
    struct node1* next;
}stack;
void push(stack **head, tree* t1) //add at front
{
    stack* a = (stack*)malloc(sizeof(stack));
    a->t = t1;
    if(*head == NULL)
    {
        a->next = NULL;
        *head = a;
    }
    else
    {
        a->next = *head;
        *head = a;
    }
}
tree* pop(stack **head) //return the element at front
{
    stack* b = *head;
    *head = (*head)->next;
    return b->t;
}
int isEmpty(stack *h)
{
    if(h == NULL)
        return 0;
    return 1;
}
tree* add_in(tree* root,int data)
{
    if(root == NULL)
    {
        tree* t = (tree*)malloc(sizeof(tree));
        t->data = data;
        t->left = NULL;     t->right = NULL;
        return t;
    }
    else if(root->data > data)
        root->left = add_in(root->left, data);
    else if(root->data < data)
        root->right = add_in(root->right, data);
    return root;
}
void zigzag(tree* root)
{
    stack *head1 = NULL;
    push(&head1, root);
    int i = 0; //0 false
    while(isEmpty(head1))
    {
        stack *head2 = NULL;
            while(isEmpty(head1))
            {
                tree *b = pop(&head1);
                printf(" %d ",b->data);
                if(i == 0)
                {
                    if(b->left != NULL)
                        push(&head2,b->left);
                    if(b->right != NULL)
                        push(&head2,b->right);
                }
                else
                {
                    if(b->right != NULL)
                        push(&head2, b->right);
                    if(b->left !=  NULL)
                        push(&head2, b->left);
                }
            }
        head1 = head2;
        i = i ^ 1;
    }
}
int main()
{
    tree* root = NULL;
    root = add_in(root, 5);
    root = add_in(root, 4);
    root = add_in(root, 3);
    root = add_in(root, 6);
    root = add_in(root, 7);
    zigzag(root);
    return 0;
} 
