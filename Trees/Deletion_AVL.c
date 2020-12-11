#include <stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
}Node;

Node* newNode(int val)
{
    Node* newnode = (Node*)malloc(1*sizeof(Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    
    return newnode;
}

int max(int a, int b)
{
    return (a>b) ? a : b;
}

int getHeight(Node* root)
{
    if(root == NULL) 
        return 0;
    
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    
    return 1 + max(l,r);
}



Node* rotateLL(Node* z)
{
    if(z == NULL) 
        return NULL;
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

Node* getMin(Node* root)
{
    if(root == NULL) 
        return root;
    
    Node* curr = root;
    while(curr!=NULL  && curr->left!=NULL) 
        curr = curr->left;
    
    return curr;
}

Node* delete(Node* root, int val)
{
    if(root == NULL) 
        return root;
    
    if(val < root->data)
        root->left = delete(root->left, val);
    
    else if (val > root->data) 
        root->right = delete(root->right, val);
    
    else
    {
        if(root->left == NULL || root->right == NULL)
        {
            Node* temp = (root->left==NULL) ? root->right : root->left;
            
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else 
                *root = *temp;
            
            free(temp);
            
        }
        else
        {
            Node* temp = getMin(root->right);
            root->data = temp->data;
            
            root->right = delete(root->right, temp->data);
            
        }
    }
    
    if(root == NULL) 
        return root;
    int bal = getHeight(root->left)-getHeight(root->right);
    
    if(bal > 1)
    {
        int balB = getHeight(root->left->left)-getHeight(root->left->right);
        if(balB >= 0) 
            return rotateRR(root);
        else
        {
            root->left = rotateLL(root->left);
            return rotateRR(root);
        }
    }
    
    if(bal <- 1)
    {
        int balB = getHeight(root->right->left)-getHeight(root->right->right);
        if(balB <= 0) 
            return rotateLL(root);
        else 
        {
            root->right = rotateRR(root->right);
            return rotateLL(root);
        }
    }
    
    return root;
}

int main()
{
    int n, val, k;
    Node* root = NULL;
    
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&val);
        root = insert(root, val);
    }
    

    preorder(root);
    printf("\n");
    
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&val);
        root = delete(root, val); 
        preorder(root);
        printf("\n");
    }
    
    return 0;
}