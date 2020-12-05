#include <stdio.h>
#include <stdlib.h>

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

void reverseList()
{
    if((head == NULL) || (head->next == NULL))
    {
        return;
    }
    
    struct Node *prev = NULL;
    struct Node *nxt = NULL;
    struct Node *curr = head;
    while (curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    
    head = prev;
}

void printlist()
{
    struct Node* temp = head;
    
    while(temp!=NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    temp = head;
    printf("NULL");
}

int main()
{
    insert_end(1);
    insert_end(2);
    insert_end(5);
    insert_end(7);
    insert_end(4);
    
    printlist();
    
    reverseList();
    
    printf("\n");
    printlist(); 
    printf("\n");

    return 0;
}