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

void preorder(TreeNode* root)
{
    stack<TreeNode*> st;
    TreeNode* curr = root;
    
    while(!st.empty() || curr!=NULL)
    {
        if(curr!=NULL)
        {
            st.push(curr);
            cout<< curr->val<< " ";
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
            curr = curr->right;
        }
    }
}

void Inorder(TreeNode *root)
{
    stack<TreeNode*> st;
 
    TreeNode *curr = root;
 
    while (!st.empty() || curr != nullptr)
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
            cout << curr->val << " ";
 
            curr = curr->right;
        }
    }
}

void Postorder(TreeNode* root) 
{
    stack<TreeNode*>stck;
    vector<int> vec;
        
    if(root==NULL)
    return;
        
       do{
            while(root)
            {
                if(root->right)
                    stck.push(root->right);
                stck.push(root);
                root=root->left;
            }

            root=stck.top();
            stck.pop();
           
            if(root->right && !stck.empty() && stck.top()==root->right)
            {
                stck.pop();
                stck.push(root);
                root=root->right;
            }
           
            else
            {
                cout<<root->val<<" ";
                
                root=NULL;
            }
           
        }while(!stck.empty());
        
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
	
	preorder(root);
	cout<<endl;
	Inorder(root);
	cout<<endl;
	Postorder(root);
	cout<<endl;
	
	return 0;
}