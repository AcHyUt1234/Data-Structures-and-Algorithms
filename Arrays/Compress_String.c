#include<stdio.h>

char* To_Lower(char* str)
{
  for(int i=0; str[i]!=0; i++)
  {
      if(str[i]>=65 && str[i]<=90)
         str[i]=str[i]+32;
  }
  
  return str;
}

void Compress_String(char *str)
{
  char ans[100];
  int count=0;
  
  for(int i=0; str[i]!=0; i++)
  {
    if(str[i] == str[i+1])
        count++;
    else
    {
      printf("%d%c", count+1, str[i]);
      count=0;
    }
  }
}

int main()
{
  int t=0;
  scanf("%d", &t);
  
  while(t--)
  {
    char s[100];
    scanf("%s",s);
    
    Compress_String(To_Lower(s));
    printf("\n");
  }

  return 0;
}