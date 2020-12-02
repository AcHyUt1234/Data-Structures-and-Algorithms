#include<stdio.h> 
#include <stdlib.h>

struct node 
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL, *tail = NULL;

struct node *createNode(int data) 
{
    struct node *newnode = (struct node *)malloc(sizeof (struct node));
    newnode->data = data;
    newnode->next = newnode->prev = NULL;
    return (newnode);
 }

void push_front(int x)
{
  struct node* push = createNode(x);
  if(head==NULL)
    head=push;
  else
  {
    push->prev = NULL;
    push->next = head;
    head->prev = push;
    head=push;
  }
}

void push_back(int x)
{
  struct node *push_val = createNode(x), *temp=head;
  if(head==NULL)
    head=push_val;
  else
  {
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    
    temp->next=push_val;
  }
}

int pop_front()
{
  struct node *temp=head, *res=NULL;
  if(head==NULL)
    return -1;
  else
  {
    temp=head->next;
    res=head;
    head=temp;
  }
  
  return res->data;
}

int pop_back()
{
  struct node* temp=head, *res=NULL;
  if(head==NULL)
    return -1;
  else if(head->next==NULL)
  {
      res=head;
      head=NULL;
  }
  else
  {
    while(temp->next->next!=NULL)
    {
      temp=temp->next;
    }
    
    res=temp->next;
    temp->next = NULL;
  }
  
  return res->data;
}

int front()
{
  struct node *res=NULL;
  if(head==NULL)
    return -1;
  else
  {
    res=head;
  }
  
  return res->data;
}

int back()
{
  struct node* temp=head, *res=NULL;
  if(head==NULL)
    return -1;
  else
  {
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    res=temp;
  }
  
  return res->data;
}

int main()
{
  int testcase=0;
  scanf("%d",&testcase);

  while(testcase--)
  {
    int operations=0, cas=0, val=-1;
    scanf("%d", &operations);
    
    while(operations--)
    {
      scanf("%d",&cas);
      
        /*
        1 : push_front(X)
        2 : push_back(X)
        3 : pop_front() (returns popped number)
        4 : pop_back()
        5 : front() (return front number)
        6 : back() (return number at back)
        */
    
      switch(cas)
      {
        case 1:scanf("%d", &val);
               push_front(val);
               break;
               
        case 2:scanf("%d",&val);
               push_back(val);
               break;
               
        case 3:printf("%d\n",pop_front());
               break;
               
        case 4:printf("%d\n",pop_back());
               break;
               
        case 5:printf("%d\n",front());
               break;
               
        case 6:printf("%d\n",back());
               break;
               
        default: printf("Enter valid operation");
      }
    }
  }
  
  return 0;
}