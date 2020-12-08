#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* create_node(int x)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}

void insert_end(int data)
{
    struct Node* t = create_node(data);
    struct Node* temp = head;

    if(head==NULL)
    head = t;
    else
    {
        while(temp->next)
        temp=temp->next;
        
        temp->next = t;
    }
}

struct Node* reverse(struct Node* slow)
{
    struct Node* prev=NULL,*curr=slow,*next;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    return prev;
}

void palindrome()
{
    struct Node* slow=head, *fast=head, *curr=NULL;
    int flag=0;
    
    while(fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    
    struct Node* temp=head;
    curr=slow;
    curr->next=reverse(slow->next);
    curr=curr->next;
    while(curr)
    {
        if(temp->data==curr->data)
        { 
            temp=temp->next;
            curr=curr->next;
        }
        else 
        {
            flag=1; 
            break;
        }
    
    }
    
    if(flag==1)
        printf("Not palindrome !!!");
    else 
        printf("Is Palindrome !!!");
}

void PrintList(struct Node* head)
{
    struct Node* counter = head;
    
    while (counter != NULL)
    {
        printf("%d ",counter->data);
        counter = counter->next;
    }
}

int main()
{
    insert_end(20);
    insert_end(18);
    insert_end(15);
    insert_end(10);
    insert_end(15);
    insert_end(18);
    insert_end(20);
    
    PrintList(head); // 20 18 15 10 15 18 20
    printf("\n");
    
    palindrome();
    
    return 0;
}