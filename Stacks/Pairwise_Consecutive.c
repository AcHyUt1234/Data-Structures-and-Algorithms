#include<stdio.h> 
#include <stdlib.h>
#include <stdbool.h> 

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;
struct node * createNode(int data) 
{
    struct node *newnode = (struct node*)malloc(sizeof (struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void push(int x)
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

int pop()
{
  struct node *temp=head,*res=NULL;
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

bool empty()
{
  if(head==NULL)
    return true;
    
  return false;
}

int main()
{
  int t=0;
  scanf("%d", &testcase);
  
  while(testcase--)
  {
    int n=0;
    scanf("%d", &n);
    int i=0, val=-1;
    
    while(i<n)
    {
        scanf("%d", &val);
        push(val);
        i++;
    }
    
    if(n%2)
        pop();
        
    int flag=0;
    
    while(!empty())
    {
      int val1=pop();
      int val2=pop();
      
      if(abs(val1-val2) != 1)
      {
          printf("No\n");
          flag=1;
          break;
      }
    }
    
    if(flag==0)
        printf("Yes\n");
  }

  return 0;
}