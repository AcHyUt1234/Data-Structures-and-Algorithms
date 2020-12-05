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

void Delete_Alternate() 
{ 
	if (head == NULL) 
		return; 

	struct Node *prev = head; 
	struct Node *node = head->next; 

	while (prev != NULL && node != NULL) 
	{ 
		prev->next = node->next; 

		free(node); 

		prev = prev->next; 
		if (prev != NULL) 
			node = prev->next; 
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
    insert_end(20);
    insert_end(18);
    insert_end(15);
    insert_end(10);
    insert_end(8);
    insert_end(6);
    insert_end(5);
    insert_end(3);
    
    printlist(); // 20->18->15->10->8->6->5->3->NULL
    printf("\n");
    
    Delete_Alternate();
    
    printlist(); // 20->15->8->5->NULL

    return 0;
}