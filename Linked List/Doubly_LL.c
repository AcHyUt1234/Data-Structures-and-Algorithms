#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    new_node->prev = NULL; 
  
    if((*head_ref) != NULL) 
        (*head_ref)->prev = new_node;
    
    (*head_ref) = new_node; 
} 

void printList(struct Node* node) 
{ 
    struct Node* last; 
    while (node != NULL) 
    { 
        printf("%d ", node->data); 
        last = node; 
        node = node->next; 
    } 
} 

int main()
{
    struct Node* head = NULL;
    
    push(&head, 6); 
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 4);
    
    printList(head);
    
    return 0;
}