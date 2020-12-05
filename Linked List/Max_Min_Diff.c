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

void Min_Max_Diff()
{
    if (head == NULL)
    {
        return;
    }
    
    if (head -> next == NULL)
    {
        printf("%d",head->data);
    }
    
    int max = INT_MIN;
    int min = INT_MAX;
    while (head != NULL)
    {
        if (head->data > max)
        {
            max = head->data;
        }
        if (head->data < min)
        {
            min = head->data;
        }
        head = head->next;
    }
    
    printf("Max = %d\n",max);
    printf("Min = %d\n",min);
    printf("Diff = %d\n",max - min);
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
    printf("\n");
    
    Min_Max_Diff();

    return 0;
}