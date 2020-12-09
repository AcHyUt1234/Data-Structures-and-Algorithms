#include <stdio.h>
#include <stdlib.h>

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

void freq(struct Node* head)
{
    int arr[100]={0}, max=-1;
    struct Node* temp=head;
    while(temp)
    {
        arr[temp->data]++;
        if(max < temp->data)
            max=temp->data;
            
        temp=temp->next;
    }
    
    for(int i=0; i<=max; i++)
    {
        if(arr[i]>0)
        {    printf("freq(%d)=%d", i, arr[i]);
            printf("\n");
        }
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
    insert_end(1);
    insert_end(2);
    insert_end(2);
    insert_end(3);
    insert_end(2);
    insert_end(3);
    
    printlist(); // 1->2->2->3->2->3->NULL
    printf("\n");
    
    freq(head); 

    return 0;
}