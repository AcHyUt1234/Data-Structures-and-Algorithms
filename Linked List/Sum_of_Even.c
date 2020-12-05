#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void Sum_of_Even()
{
    int sum = 0;
    struct Node* temp = head;
    
    if (head == NULL)
        return;
        
    if (head->next == NULL)
    {
        if ((head->data % 2) == 0)
        {
            sum += head->data;
            printf("%d\n",sum);
            return;
        }
    }
    
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
            sum += temp->data;
        temp = temp->next;

    }
    
    printf("%d\n",sum);
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
    insert_end(2);
    insert_end(2);
    insert_end(5);
    insert_end(7);
    insert_end(4);
    
    printlist();
    printf("\n");
    
    Sum_of_Even();

    return 0;
}