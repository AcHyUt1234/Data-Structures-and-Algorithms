#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* create_node(char x)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}

void insert_end(char new_char)
{
    
    struct Node* t = create_node(new_char);
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
        printf("%c->", temp->data);
        temp = temp->next;
        
    }
    temp = head;
    printf("NULL");
}

int main()
{
    char str[]="abacabd";
    int i;
    
    for(i=0; str[i]!='\0'; i++)
    insert_end(str[i]);
    
    printlist();
    printf("\n");


    return 0;
}