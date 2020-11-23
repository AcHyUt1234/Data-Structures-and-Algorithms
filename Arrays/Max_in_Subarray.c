#include<stdio.h>

#define INT_MIN (-2147483647 - 1);

void maximum(int arr[],int s,int k,int n)
{
  int max=INT_MIN;
  
  for(int i=s; i<k+s; i++)
  {
    if(max < arr[i])
    {
      max = arr[i];
    }
  }

  printf("%d ",max);
}

void Max_Subarray(int arr[], int n, int k)
{
  int i=0;
    while(i <= n-k)
    {
        maximum(arr, i, k, n);
        i++;
    }
  
}

int main()
{
int n=0, t=0, k=0;

  scanf("%d",&t);
  
  while(t--)
  {
    scanf("%d%d", &n, &k);
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
      scanf("%d", &arr[i]);
    }
    
    Max_Subarray(arr, n, k);
    printf("\n");
  }
  return 0;
}