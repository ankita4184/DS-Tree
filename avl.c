#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node{
    struct node* left;
    struct node* right;
    int data;
    int height;
}tree;

int Height(tree* root){
    if(root == NULL)
        return -1;
    int a = 1 + Height(root->left);
    int b = 1 + Height(root->right);
    if(a > b)
        return a;
    return b;
}
int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
tree* SingleRotateL(tree* root){
    tree* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->height = max(Height(root->left), Height(root->right)) + 1;
    temp->height = max(Height(temp->left), Height(temp->right)) + 1;
    return temp;
} 
tree* SingleRotateR(tree* root){
    tree* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = max(Height(root->left), Height(root->right)) + 1;
    temp->height = max(Height(root->left), Height(root->right)) + 1;
    return temp;
}
tree* DoubleRotateL(tree* root){
    root->left = SingleRotateR(root->left);
    return SingleRotateL(root);
}
tree* DoubleRotateR(tree* root){
    root->right = SingleRotateL(root->right);
    return SingleRotateR(root);
}
tree* insert(tree* root, int d){
    if(root == NULL){
        tree* t = (tree*)malloc(sizeof(tree));
        t->data = d;
        t->height = 0;
        t->left = t->right = NULL;
        return t;
    }
    else if(root->data > d){
        root->left = insert(root->left, d);
        if(Height(root->left) - Height(root->right) == 2){ //imbalance case of left side
            if((root->left)->data > d) //node ke left ke left mein add hua
                root = SingleRotateL(root);
            else
                root = DoubleRotateL(root);
        }
    }
    else if(root->data < d){
        root->right = insert(root->right, d);
        if(Height(root->right) - Height(root->left) == 2){ //imbalance case of right side
            if((root->right)->data < d)
                root = SingleRotateR(root);
            else
                root = DoubleRotateR(root);
        }
    }
    root->height = max(Height(root->left), Height(root->right)) + 1;
    return root;
}
void inorder(tree* root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d  %d\n",root->data, root->height);
    inorder(root->right);
}
int main(){
    tree* root = NULL;
    root = insert(root, 70);
    root = insert(root, 500);
    root = insert(root, 30000);
    root = insert(root, 2);
    root = insert(root, 10);
    root = insert(root, -4);
//    root = insert(root, 60);
    printf("%d",(Height(root->left) - Height(root->right)));
}
