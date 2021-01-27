#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL,*rear = NULL,*p = NULL,*np = NULL;

void push(int x)
{
    np = new Node;
    np->data = x;
    np->next = NULL;
    if(front == NULL)
    {
        front = rear = np;
        rear->next = NULL;
    }
    else
    {
        rear->next = np;
        rear = np;
        rear->next = NULL;
    }
}

int remove()
{
    int x;
    if(front == NULL)
    {
        cout<<"empty queue\n";
        return -1;
    }
    else
    {
        p = front;
        x = p->data;
        front = front->next;
        delete(p);
        return x;
    }
}

void display()
{
    struct Node* temp = front;
    while(temp !=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    push(3);
    push(4);
    push(5);
    display();
    remove();
    display();
    push(6);
    display();
    remove();
    remove();
    remove();
    display();
    remove();
    
    return 0;
}