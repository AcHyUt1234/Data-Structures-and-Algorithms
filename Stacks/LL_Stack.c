#include <stdio.h> 
#include <stdlib.h>

struct node   
{  
int value;  
struct node *next;  
}; 

struct node *head;

void push(int value)  
{   
    struct node *ptr =(struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL)  
    {  
        printf("-1");   
    }  
    else   
    {    
        if(head==NULL)  
        {         
            ptr->value = value;  
            ptr -> next = NULL;  
            head=ptr;  
        }   
        else   
        {  
            ptr->value = value;  
            ptr->next = head;  
            head=ptr;      
        }   
          
    }  
}

void pop()  
{  
    int item;  
    struct node *ptr;  
    if (head == NULL)  
    {  
        printf("Stack Underflow\n");  
    }  
    else  
    {  
        item = head->value;  
        ptr = head;  
        head = head->next;  
        free(ptr);   
    }  
}  

void traverse()  
{  
    int i;  
    struct node *ptr;  
    ptr = head;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {   
        while(ptr!=NULL)  
        {  
            printf("%d ", ptr->value);  
            ptr = ptr->next;  
        }  
    }  
}  

int main()
{
    push(2);
    push(3);
    push(4); 
    
    traverse(); // 4 3 2
    printf("\n");
    
    pop(); 
    
    traverse(); // 3 2
    printf("\n");

    push(5);
    push(6);

    traverse(); // 6 5 3 2
    printf("\n");

    pop();
    pop();
    pop();
    pop(); //Stack emptied
    pop(); //Stack Underflow
    
    traverse(); //Empty Stack
    printf("\n");

    return 0;
}