#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

Node* head = NULL;

Node* create_Node(int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(int data)
{
    Node* new_node = create_Node(data);
    Node* temp = head;
    
    if(head==NULL)
        head = new_node;
    else
    {
        while(temp->next)
        temp = temp->next;
        
        temp->next = new_node;
    }
    
}

void deleteNode(int key)
{
    Node* temp = head;
    Node* prev;
    
    if(temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return;
    }
    
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL)
    return;
    
    prev->next = temp->next;
    
    free(temp);
    
}

void printList()
{
    Node* temp = head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    
    cout<<"NULL";
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    
    printList();
    
    deleteNode(3);
    
    printList();
    
    return 0;
}

