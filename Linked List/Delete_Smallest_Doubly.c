// delete the smallest number from the doubly linked list

#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

struct Node{
    int val;
    struct Node* prev;
    struct Node* next;
};

void push(struct Node** head, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node->val = new_data;
    new_node->next = (*head);
    new_node->prev = NULL;
    
    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }
    
    (*head) = new_node;
}

struct Node* del_pointer(struct Node* head)
{
    int min = INT_MAX;
    struct Node* temp = head;
    struct Node* del = NULL;
    
    while (temp != NULL)
    {
        if (temp->val < min)
            min = temp->val;
        temp = temp->next;
    }
    
    struct Node* flag = head;
    
    while (flag->val != min)
    {
        flag = flag->next;
    }
    
    return flag;
}

void deleteNode(struct Node* head, struct Node* del)
{
    if (head == NULL || del == NULL)
        return;
 
    if (head == del)
        head = del->next;
        
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    if (del->prev != NULL)
        del->prev->next = del->next;
 
    free(del);
    return;
}

void PrintLinkedList(struct Node* head)
{
    if (head == NULL)
    {
        return;
    }
    
    while (head != NULL)
    {
        printf("%d ",head->val);
        head = head->next;
    }
}

int main()
{
    struct Node* head = NULL;
    
    push(&head,7);
    push(&head,3);
    push(&head,2);
    push(&head,6);
    
    PrintLinkedList(head); // 6 2 3 7
    
    struct Node* del = del_pointer(head);
    deleteNode(head, del);
    
    printf("\n");
    PrintLinkedList(head); // 6 3 7
    
    return 0;

}