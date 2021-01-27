#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data)
{
    struct Node* temp = new Node();
    
    temp->data = data;
    temp->next = top;
    top = temp;
}

int pop()
{
    struct Node* temp;
    
    if(top==NULL)
    {
        cout<<"Stack Underflow!!";
        return -1;
    }
    else
    {
        temp = top;
        top = top->next;
        int x = temp->data;
        free(temp);
        return x;
    }
}

void display()
{
    struct Node* temp=top;
    
    if(top == NULL)
    {
        cout<<"Stack Underflow";
    }
    else
    {
        while(temp)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
}

int isEmpty()
{
    return top == NULL;
}

int peek()
{
    if(!isEmpty())
        return top->data;
    else 
        return -1;
}

int evaluatePostfix(char exp[])
{
    if(isEmpty())
        return -1;
    
    int n = strlen(exp);  
    
    for(int i=0; i<n; i++)
    {
        if(isdigit(exp[i]))
            push(exp[i]-'0');
        else
        {
            int val1 = pop();
            int val2 = pop();
            switch (exp[i])  
            {  
            case '+': push(val2 + val1); break;  
            case '-': push(val2 - val1); break;  
            case '*': push(val2 * val1); break;  
            case '/': push(val2/val1); break;  
            } 
        }
    }
    
    return pop();
    
}

int main()
{
    char str[] = "231*+9-";
    
    cout<<evaluatePostfix(str);
    
    return 0;
}