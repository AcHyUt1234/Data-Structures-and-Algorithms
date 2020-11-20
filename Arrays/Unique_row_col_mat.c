#include <stdio.h>

void swap(int* xp, int* yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// Function to perform Selection Sort 
void sort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n - 1; i++) 
    { 
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
                
        swap(&arr[min_idx], &arr[i]); 
    } 
} 

void  unique_row(int num,int arr[][num],int along)
{
  switch(along)
  {
    case 1:printf("Along rows:\n");break;
    case 2:printf("Along columns:\n");break;
    default:printf("Matrix:\n");
  }
  
  int uni_mat[num*num], t=0;
  
   for(int i=0; i<num; i++)
   {
     int ans[num];
      for(int j=0; j<num; j++)
      {
        switch(along)
        {
          case 1:ans[j]=arr[i][j];break;
          case 2:ans[j]=arr[j][i];break;
          default:uni_mat[t++]=arr[i][j];
        }
      }
      
      if(along==1 || along ==2)
      {
        sort(ans,num);
        for(int k=1; k<num+1; k++)
        {
          if(ans[k-1]!=ans[k])printf("%d ",ans[k-1]);
        }
        printf("\n");
      }
   }
   
   if(along==3)
   {
     sort(uni_mat, num*num);
     
        for(int k=1; k<num*num+1; k++)
        {
          if(uni_mat[k-1] != uni_mat[k])
          printf("%d ",uni_mat[k-1]);
        }
        printf("\n");
   }
}

int main() 
{  
   int num=0;
   
    scanf ("%d",&num);
    int arr[num][num];
    
    for(int i=0;i<num;i++)
    {
      for(int j=0;j<num;j++)
      {
        scanf("%d",&arr[i][j]);
      }
    }
    
  unique_row(num,arr,1);// along row
  unique_row(num,arr,2); // along column
  unique_row(num,arr,3); //matrix
  
    return 0; 
} 