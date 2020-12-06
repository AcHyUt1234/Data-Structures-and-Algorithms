#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node*prev;
};

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    
    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }
    
    (*head_ref) = new_node;
}

void reverse(struct Node** head_ref)
{
    struct Node* temp = NULL;
    struct Node* curr = *head_ref;
    
    while (curr !=  NULL)
    {
       temp = curr->prev; 
       curr->prev = curr->next; 
       curr->next = temp;               
       curr = curr->prev; 
    }
    
    if(temp != NULL ) 
       *head_ref = temp->prev;  
}

void printList(struct Node *node) 
{ 
  while(node!=NULL) 
  { 
   printf("%d ", node->data); 
   node = node->next; 
  } 
}  

int main()
{
    struct Node* head = NULL; 
    
    push(&head, 5); 
    push(&head, 10); 
    push(&head, 15); 
    push(&head, 20);
    push(&head, 25);
    
    printList(head); // 25 20 15 10 5
    printf("\n");
    
    reverse(&head);
    
    printList(head); // 5 10 15 20 25
    
    return 0;
}