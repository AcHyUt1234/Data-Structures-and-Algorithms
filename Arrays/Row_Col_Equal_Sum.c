#include <stdio.h>

int main() 
{
	int n;
	scanf("%d",&n);
	int arr[n][n];
	int row[n], col[n];
	
	for (int i=0;i<n;i++)
	{
	    for(int j=0; j<n; j++)
	    {
	        scanf("%d ", &arr[i][j]);
	    }
	}
	
	for (int i=0; i<n; i++)
	{
	    row[i]=0;
	    col[i]=0;
	    
	    for(int j=0; j<n; j++)
	    {
	        row[i]+=arr[i][j];
	        col[i]+=arr[j][i];
	    }
	}
	
	int flag=0;
	
	for(int i=0; i<n; i++)
	{
	  for(int j=0; j<n; j++)
	  {
	      if(row[i]==col[j])
	      {
	          printf("Row: %d", i+1);
	          printf("\nColumn: %d", j+1);
	          flag=1;
	          break;
	      }
	  }
	  if(flag)
	  break;
	}
	return 0;
}

