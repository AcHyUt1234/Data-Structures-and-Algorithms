#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
   int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[], int n, int i)
{
    int large = i;
    int l=2*i+1;
    int r=2*i+2;
    
    if(l<n && arr[l] < arr[large])
    {
        large = l;
    }
    
    if(r<n && arr[r]<arr[large])
    {
        large = r;
    }
    
    if(large!=i)
    {
        swap(&arr[i], &arr[large]);
        
        heapify(arr, n, large);
    }
}

void printHeap(int arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
        
     printf("\n");
}

void buildHeap(int arr[], int n)
{
    int si = ((n/2) -1);
    
    for(int i=si; i>=0; i--)
        heapify(arr,n,i);
}

void sortHeap(int arr[], int ans[], int n, int* i)
{
    if(n==0)
        return;
        
    ans[(*i)++] = arr[0];
    
    for(int j=1;j<n;j++)
        arr[j-1]=arr[j];
    
    n--;
    
    buildHeap(arr, n);
    sortHeap(arr, ans, n, i);
}


int main() 
{
	int testcase;
	scanf("%d", &testcase);
	
	while(testcase--)
	{
	    int n,i=0;
	    scanf("%d",&n);
	    int arr[n],ans[n];
	    
	    for(int i=0; i<n; i++)
	    {
	        scanf("%d", &arr[i]);
	    }
	    
	    buildHeap(arr, n);
	    sortHeap(arr, ans, n, &i);
	    printHeap(ans, n);
	}
	
	return 0;
}
