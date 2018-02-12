#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;  //node sum 
    int no;    //node ka data
    struct node* next;
}link;
typedef struct node1{
    int data;
    struct node1* left;
    struct node1* right;
}tree;
link* head = NULL;
void push(int i, int node)
{
     if(head == NULL)
    {
        link* n = (link*)malloc(sizeof(link));
        n->data = i;
        n->no = node;
        n->next = NULL;
        head = n;
    }
    else
    {
        link *b = head;
        link *c = NULL;
        while(b != NULL && b->data < i)
        {
             c = b;
             b = b->next;
        }
        // case 1 : add at end
        //add at front
        //case 2: add at some pos.
        //case 3: same value exsists
        if(b == NULL) // reached at end and c is pointing to the last node
        {
            link* n = (link*)malloc(sizeof(link));
            n->data = i;
            n->no = node;
            n->next = NULL;
            c->next = n;
        }
        else if(b->data == i);
        else if(c == NULL) // add at front
        {
            link* n = (link*)malloc(sizeof(link));
            n->data = i;
            n->no = node;
            n->next = head;
            head = n;
        }
        else if(b->data > i && c->data < i)
        {
            link* n = (link*)malloc(sizeof(link));
            n->data = i;
            n->no = node;
            c->next = n;
            n->next = b;
        }
    }
}
void print()
{
    link* h = head;
    while(h != NULL)
    {
        printf("  %d  ", h->no);
        h = h->next;
    }
}
tree* add_in(tree *root, int data)
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
        root->left = add_in(root->left, data);
    else if(root->data < data)
        root->right = add_in(root->right, data);
    return root;
}
void traverse(tree* root, int s)
{
    if(root == NULL)
        return;
    traverse(root->left, s-1);
    push(s,root->data);
    traverse(root->right,s+1);
}
int main()
{
    int s = 0;
    tree* root = NULL;
    root = add_in(root, 5);
    root = add_in(root, 10);
    root = add_in(root, 4);
    root = add_in(root, 9);
    root = add_in(root, 8);
    root = add_in(root, 7);
    root = add_in(root, 6);
    root = add_in(root, 11);
    traverse(root, s);
    print();
    return 0;
}
        
