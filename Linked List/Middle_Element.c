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

void PrintList(struct Node* head)
{
    struct Node* counter = head;
    
    while (counter != NULL)
    {
        printf("%d ",counter->data);
        counter = counter->next;
    }
}

void middle(struct Node* head)
{
    struct Node* fast=head, *slow=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    printf("%d", slow->data);
}

int main()
{
    int k;
    scanf("%d",&k);
    
    insert_end(20);
    insert_end(18);
    insert_end(15);
    insert_end(10);
    insert_end(8);
    insert_end(6);
    insert_end(5);
    insert_end(3);
    insert_end(7);
    
    PrintList(head); // 20 18 15 10 8 6 5 3 7
    printf("\n");
    
    middle(head); // 8
    
    return 0;
}
