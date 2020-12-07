#include<stdio.h>
#include<stdlib.h>

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

void PrintList(struct Node* head)
{
    struct Node* counter = head;
    while (counter != NULL)
    {
        printf("%d ",counter->data);
        counter = counter->next;
    }
}

void solution(struct Node* head, int k)
{
    int count = 0;
    struct Node* curr = head;
    while (curr != NULL)
    {
        if ((count % k) == 0)
            printf("%d ",curr->data);
        curr = curr->next;
        count += 1;
    }
}

int main()
{
    int k;
    scanf("%d",&k);
    
    insert_end(12);
    insert_end(15);
    insert_end(18);
    insert_end(17);
    insert_end(19);
    insert_end(20);
    insert_end(22);
    
    PrintList(head); // 12 15 18 17 19 20 22
    printf("\n");
    
    solution(head,k); // 12 17 22
    
    return 0;
}
