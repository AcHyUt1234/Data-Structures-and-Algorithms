#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int val1, val2;
    struct Node* next;
};

struct Node* create(int val1, int val2)
{
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node*));
    new_node->val1=val1;
    new_node->val2=val2;
    new_node->next=NULL;
    return new_node;
}

void push(struct Node** head, int val1, int val2)
{
    struct Node* node =create(val1, val2);
    struct Node* temp=(*head);
    
    if(temp==NULL)
        temp=node;
    else
    {
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=node;
    }
}

void sum(struct Node** res, struct Node* head1, struct Node* head2)
{
    if((*res)==NULL)
        (*res)=create(0, 0);
    struct Node* result=(*res);

    while(head1 && head2)
    {
        if(head1->val2==head2->val2)
        {
            result->next=create(head2->val1+head1->val1,head1->val2);
            head1=head1->next;
            head2=head2->next;
        }
        
        else if(head1->val2>head2->val2){
            result->next=create(head1->val1,head1->val2);
            head1=head1->next;
        }
        else{
            result->next=create(head2->val1,head2->val2);
            head2=head2->next;
           
        }
       
        result=result->next;
    }
    
    while(head1)
    {
        result->next=head1;
    }
    
    while(head2)
        result->next=head2;
    
    (*res)=(*res)->next;
    printf("\n");
    
    while((*res))
    {
        if((*res)->next==NULL)
        {
	        printf("%dx^%d",(*res)->val1,(*res)->val2);
	    }
	    else
            printf("%dx^%d+",(*res)->val1,(*res)->val2);
            
        (*res)=(*res)->next;
    }
}

int main(void) 
{
	struct Node* head1=(struct Node*)malloc(sizeof(struct Node));
	struct Node* head2=(struct Node*)malloc(sizeof(struct Node));
	struct Node* res=(struct Node*)malloc(sizeof(struct Node));
	
	push(&head1,3,2);
	push(&head1,4,1);
	push(&head1,2,0);
	
	struct Node* temp1 = head1->next;
	while(temp1)
	{
	    if(temp1->next==NULL)
	    {
	        printf("%dx^%d",temp1->val1,temp1->val2);
	    }
	    else
            printf("%d*x%d+",temp1->val1,temp1->val2);
            
        temp1=temp1->next;
    }
    
	push(&head2,3,3);
	push(&head2,5,1);
	push(&head2,6,0);
	printf("\n");
	
	struct Node* temp2 = head2->next;
	while(temp2)
	{
	    if(temp2->next==NULL)
	    {
	        printf("%dx^%d",temp2->val1,temp2->val2);
	    }
	    else
            printf("%dx^%d+",temp2->val1,temp2->val2);
        
        temp2=temp2->next;
    }
    
	sum(&res, head1->next, head2->next);
	
	return 0;
}