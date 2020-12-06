#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node 
{
    int val;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node->val = new_data;
    new_node->next = (*head);
    new_node->prev = NULL;
    
    if((*head) != NULL)
    {
        (*head)->prev = new_node;
    }
    
    (*head) = new_node;
}

void FindMin(struct Node* head)
{
    int min = INT_MAX;
    if (head == NULL)
    {
        return;
    }
    
    while (head != NULL)
    {
        if (head->val < min)
        {
            min = head->val;
        }
        head = head->next;
    }
    
    printf("\n%d", min);
    return;
}

void printList(struct Node* node) 
{ 
    struct Node* last; 
    while (node != NULL) 
    { 
        printf("%d ", node->val); 
        last = node; 
        node = node->next; 
    } 
} 

int main()
{
    struct Node* head = NULL;
    
    push(&head, 6);
    push(&head, 1);
    push(&head, -6);
    push(&head, 76);
    push(&head, 34);
    push(&head, 6);
    
    printList(head); // 6 34 76 -6 1 6
    
    FindMin(head); // -6
    
    return 0;
}