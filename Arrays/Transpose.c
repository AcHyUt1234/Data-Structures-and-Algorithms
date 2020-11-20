#include<stdio.h>

void Transpose(int m, int n, int arr[m][n])
{
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      printf("%d ",arr[j][i]);
    }
    
    printf("\n");
  }
}

int main()
{
  int m=0, n=0;
  
  scanf("%d %d", &m, &n);
  
  int arr[m][n];
  
  for(int i=0; i<m; i++)
  {
    for(int j=0; j<n; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  Transpose(m,n,arr);
  
  return 0;
}