#include <stdio.h>

int main(void) 
{
    int n;
	scanf("%d",&n);
	int arr[n][n];
	
	int row[4]={0,-1,0,1}, col[4]={-1,0,1,0};
	
	for (int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        scanf("%d ",&arr[i][j]);
	    }
	}
	
	int flag=0;
	
    for (int i=0;i<n;i++)
    {
        int sum=0;
         for(int k=0;k<4;k++)
         {
            if(i+row[k]<n && i+row[k]>=0 && i+col[k]<n && i+col[k]>=0)
            {
                sum += arr[i+row[k]][i+col[k]];
                
            }
         }
         
	     if(arr[i][i]!=sum) 
	     {
	         flag=1;
	         break;
	     }
    }
    
	if(flag)
	    printf("No");
	else 
	    printf("Yes");
	    
	return 0;
}

