#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
	int data; 
	struct Node* next; 
};

void sortedInsert(struct Node**, struct Node*); 

void insertionSort(struct Node **head_ref) 
{ 
	struct Node *sorted = NULL; 

	struct Node *current = *head_ref; 
	while (current != NULL) 
	{ 
		struct Node *next = current->next; 

		sortedInsert(&sorted, current); 

		current = next; 
	} 

	*head_ref = sorted; 
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
		while (current->next!=NULL && current->next->data < new_node->data) 
		{ 
			current = current->next; 
		} 
		new_node->next = current->next; 
		current->next = new_node; 
	} 
} 

void printList(struct Node *head) 
{ 
	struct Node *temp = head; 
	while(temp != NULL) 
	{ 
		printf("%d ", temp->data); 
		temp = temp->next; 
	} 
} 

void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 

	new_node->data = new_data; 

	new_node->next = (*head_ref); 

	(*head_ref) = new_node; 
} 

int main() 
{ 
	struct Node *head = NULL; 
	
	push(&head, 5); 
	push(&head, 20); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 30); 
	
	printList(head); 
	
	insertionSort(&head); 

	printf("\nLinked List after sorting\n"); 
	printList(head); 

	return 0; 
} 
