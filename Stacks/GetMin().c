#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

int s1[100], s2[100];
int top1=-1, top2=-1, min_v;

void push(int x)
{
    if(top1==-1)
    {
        min_v=x;
        s1[++top1]=x;
    }
    else
    {
        if(x<min_v)
        {
            s1[++top1] = 2*x-min_v;
            min_v=x;
        }
        else
        {
            s1[++top1]=x;
        }
    }
}

int pop()
{
    int t=top();
    s1[top1--];
    
    if(t<min_v)
    {
        int m = min_v;
        min_v = 2*min_v-t;
        return m;
    }
    
    return t;
}

int top()
{
    return s1[top1];
}

int getmin()
{
    return min_v;
}

int main() 
{
    int arr[]={4, 7, 3, 2, 10}; // topmost element: 10
    
    for(int i=0; i<5; i++)
    {
        push(arr[i]);
    }
    
    while(top1!=-1)
    {
        printf("%d ", getmin()); // 2 2 3 4 4
        pop();
    }
    
    return 0;
}
