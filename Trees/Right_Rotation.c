#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* newNode(int val)
{
    Node* newnode = (Node*)malloc(1*sizeof(Node));
    newnode->data = val;
    newnode->left  = NULL;
    newnode->right = NULL;
    
    return newnode;
}

Node* rotateRR(Node* z)
{
    
    if(z == NULL) 
        return NULL;
    
    Node* temp = z->left;
    Node* temp1;
    
    if(temp->right) 
        temp1 = temp->right;
    else 
         temp1 = NULL;
    
    temp->right = z;
    z->left = temp1;
    
    return temp;
}

Node* insert(Node* root, int val)
{
    if(root == NULL) 
        return newNode(val);
    
    if(val < root->data) 
        root->left = insert(root->left, val);
    
    else 
        root->right = insert(root->right, val);
    
    return root;
}

void preorder(Node* root)
{
    if(root == NULL) 
        return;
    
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
    
}

void inorder(Node* root)
{
    
    if(root == NULL) 
        return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
    
}

int main()
{
    int n, val;
    
    Node* root = NULL;
    
    scanf("%d",&n);
    
    for(int i=0; i<n; i++)
    {
        scanf("%d",&val);
        root = insert(root, val);
    }
    
    inorder(root);
    printf("\n");
    
    root = rotateRR(root);
    preorder(root);

    return 0;
}