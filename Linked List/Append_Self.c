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

void append_list()
{
    struct Node* temp = head;
    struct Node* curr;
    int count = 0;
    
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    
    temp = head;
    
    while(count)
    {
        insert_end(temp->data);
        temp = temp->next;
        count--;
    }
    
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
    insert_end(3);
    insert_end(4);
    
    printlist(); // 1->2->3->4->NULL
    printf("\n");
    
    append_list();
    printlist(); // 1->2->3->4->1->2->3->4->NULL

    return 0;
}