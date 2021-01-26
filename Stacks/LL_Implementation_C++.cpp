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
    struct Node* temp;
    temp = new Node();
    
    temp->data = data;
    temp->next = top;
    top = temp;
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
    exit(1);
}

int pop()
{
    struct Node* temp;
    
    if(top == NULL)
    {
        cout<<"Stack Underflow"<<endl;
        exit(1);
    }
    else
    {
        temp = top;
        top = top->next;
        int x = temp->data;
        temp->next = NULL;
        free(temp);
        return x;
    }
}

void display()
{
    struct Node* temp = top;
    
    if(top == NULL)
    {
        cout<<"Stack Underflow"<<endl;
        exit(1);
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

int main()
{
    push(11);  
    push(22);  
    push(33);  
    push(44);  
  
    // Display stack elements  
    display();  
  
    // Print top element of stack  
    // cout << "\nTop element is "<< peek() << endl;  
  
    // // Delete top elements of stack  
    cout<<"Deleted: "<<pop()<<endl;  
    cout<<"Deleted: "<<pop()<<endl;  
  
    // Display stack elements  
    display();  
  
    // Print top element of stack  
    cout << "Top element is " << peek() << endl; 
    
    return 0;
}