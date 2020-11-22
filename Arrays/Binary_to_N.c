#include<stdio.h>

void findBinary(int n)
{
 if (n > 1) 
    findBinary(n/2);
    
  printf("%d", n%2);
}

int main()
{
  int n=0,t=0;
  scanf("%d", &t);
  
  while(t--)
  {
    scanf("%d",&n);
    
    for(int i=1; i<=n; i++)
    {
      findBinary(i);
      printf(" ");
    }
    
    printf("\n");
  }
  
  return 0;
}