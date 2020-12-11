#include <stdio.h>
#include<stdlib.h>

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

int max(int a, int b)
{
    return (a>b) ? a:b;
}

int getHeight(Node* root)
{
    if(root == NULL) 
        return 0;
    
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    
    return 1 + max(l,r);
}

Node* rotateRR(Node* z)
{
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

Node* rotateLL(Node* z)
{
    Node* temp = z->right;
    
    Node* temp1;
    if(temp->left) 
        temp1 = temp->left;
    else
        temp1 = NULL;
    
    temp->left = z;
    z->right = temp1;
    
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
    
    int bal = getHeight(root->left) - getHeight(root->right);
    
    if(-1 <= bal && bal <= 1) 
        return root;
    
    if(bal>1 && val < root->left->data) 
        return rotateRR(root);
    
    if(bal < -1 && val > root->right->data) 
        return rotateLL(root);
    
    if(bal > 1 && val > root->left->data)
    {
        root->left = rotateLL(root->left);
        return rotateRR(root);
    }
    
    if(bal < -1 && val < root->right->data)
    {
        root->right = rotateRR(root->right);
        return rotateLL(root);
    }

}

void preorder(Node* root)
{
    if(root == NULL) 
        return;
    
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
    
}

int main()
{
    int n, val, t;
    
    scanf("%d", &t);
    
    while(t--)
    {
        Node* root = NULL;
    
        scanf("%d", &n);
    
        for(int i=0; i<n; i++)
        {
            scanf("%d", &val);
            root = insert(root, val);
        }
    
        preorder(root);
        printf("\n");
    }

    return 0;
}
