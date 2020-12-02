#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

struct node *createNode(int data) 
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}
  
void enqueue(int x)
{
  struct node* push_val = createNode(x), *temp=head;
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

int dequeue()
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

int size()
{
  struct node *temp=head;
  int count=0;
  
  while(temp!=NULL)
  {
    temp=temp->next;
    count++;
  }
  
  return count;
}

void printQueue()
{
  while(head)
  {
      printf("%d ",head->data);
      head=head->next;
  }
}

int main()
{
  int n=0, k=0;
  scanf("%d %d", &n, &k);
  
  int arr[n], val;
  for(int i=0; i<k; i++)
  {
    scanf("%d", &val);
    enqueue(val);
    int size_q=size()-1;
    while(size_q--)
    {
      int x = dequeue();
      enqueue(x);
    }
    
  }
  
  for(int i=k; i<n; i++)
  {
    scanf("%d",&val);
    enqueue(val);
  }
  
  printQueue();
  
  return 0;
}