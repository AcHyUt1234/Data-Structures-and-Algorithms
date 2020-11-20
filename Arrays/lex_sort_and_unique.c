#include<stdio.h>
#include<stdlib.h>

int (strcmp)(const char *s1, const char *s2)
 {
     unsigned char uc1, uc2;
     while (*s1 != '\0' && *s1 == *s2) 
     {
         s1++;
         s2++;
     }

     uc1 = (*(unsigned char *) s1);
     uc2 = (*(unsigned char *) s2);
     return ((uc1 < uc2) ? -1 : (uc1 > uc2));
 }

 char *(strcpy)(char *restrict s1, const char *restrict s2)
 {
     char *dst = s1;
     const char *src = s2;
     while ((*dst++ = *src++) != '\0') ;               
     return s1;
 }

int main()
  {
    int n, i, j;
    scanf("%d", &n);
    char arr[n][100], temp[n][100];

    for(i=0;i<n; i++)
    scanf("%s", arr[i]);
 
        for (i = 0; i < n - 1 ; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (strcmp(arr[i], arr[j]) > 0) 
                {
                    strcpy(temp, arr[i]);
                    strcpy(arr[i], arr[j]);
                    strcpy(arr[j], temp);
                }
            }
        }

      printf("Sorted:\n");
      for (i = 0; i < n; i++) 
        {
            printf("%s ", arr[i]);
        }

        printf("\nUnique\n");
      
      for (i=0; i<n;i++)
      {
        if(strcmp(arr[i], arr[i+1])==0)
        continue;
        printf("%s ", arr[i]);
      }
      
    return 0; 
  }
