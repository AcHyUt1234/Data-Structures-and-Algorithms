#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

struct Node* head = NULL;

void insertion_sort()
{
    struct Node* sorted = NULL;
    struct Node* curr = head;
    
    while(curr!=NULL)
    {
        struct Node* next = curr->next;
        
        sortedInsert(&sorted, curr);
        
        curr = next;
    }
    
    head = sorted;
}

void sortedInsert(struct Node** head_ref, struct Node* new_node) 
{ 
    struct Node* current; 

    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) 
    { 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    } 
    else
    { 
        current = *head_ref; 
        while (current->next!=NULL && 
               current->next->data < new_node->data) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 

void printList()
{
    struct Node* temp = head;
    
    while(temp!=NULL)
    {
    printf("%d->", temp->data);
    temp = temp->next;
    }
    printf("NULL");
}

int main(void) 
{
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    struct Node* fifth = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;
    
    third->data = 5;
    third->next = fourth;
    
    fourth->data = 7;
    fourth->next = fifth;
    
    fifth->data = 4;
    fifth->next = NULL;
    
    printList();
    printf("\n");
    
    insertion_sort();
    
    printList();
	
	return 0;
}