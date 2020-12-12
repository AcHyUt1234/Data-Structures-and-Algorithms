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

void swap(int* a, int* b) 
{ 
    int temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void swap_kth(int k)
{
    int count = 0;
    int count_total = 0;
    struct Node* current = head;
    while (current != NULL) 
    { 
        count_total++; 
        current = current->next; 
    } 
    
    if(k>0 && k<=count_total)
    {
        struct Node* temp1 = head;
    
    struct Node* temp2 = head;
    
    while(temp1)
    {
        count++;
        if(count==k)
        break;
        temp1 = temp1->next;
    }
    
    count = 0;
    
    while(temp2)
    {
        if(count==(count_total-k))
        break;
        
        count++;
        temp2 = temp2->next;
    }
    
    swap(&temp1->data, &temp2->data);
    printlist();
    }
    else
        printf("Wrong k entry!!");
}

int main()
{
    int k;
    scanf("%d", &k);
    
    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(4);
    insert_end(5);
    
    printlist();
    printf("\n");
    
    swap_kth(k);
    printf("\n");

    return 0;
}