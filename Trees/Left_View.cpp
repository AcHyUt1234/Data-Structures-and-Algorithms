#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
};

typedef struct TreeNode TreeNode;

TreeNode* insert(TreeNode* root, int val)
{
    if(!root)
    {
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    
    if(val<=root->val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    
    return root;
}

void leftview(TreeNode* root)
{
    vector<int> ans;
    
    if(!root)
        return;
    
    if(!root->right && !root->left)
    {
        cout<<root->val;
        return;
    }
    
    TreeNode* curr = root;
    
    while(curr != NULL)
    {
        cout<<curr->val<<" ";
        if(!curr->left)
            {
                if(curr->right)
                {
                curr = curr->right;
                }
                else
                    curr = NULL;
            }
        else
        {
            curr = curr->left;
        }
        
    }

}

int main() 
{
	int n;
	scanf("%d", &n);
	
	TreeNode* root = NULL;
	int val;
	
	for(int i=0; i<n; i++)
	{
	    scanf("%d", &val);
	    root = insert(root, val);
	}
	
	leftview(root);
	
	return 0;
}