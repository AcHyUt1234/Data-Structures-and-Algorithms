#include <stdio.h> 
#include <string.h> 
  
void isPalindrome(char str[]) 
{ 
    int l = 0; 
    int h = strlen(str) - 1; 
 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            printf("no"); 
            return; 
        } 
    } 
    printf("yes"); 
} 

int main() 
{ 
    int testcase;
    scanf("%d", &testcase);

    while(testcase--)
    {
        int flag = 0;
        char str[10];
        scanf("%s", str);
        
        int l = 0; 
        int h = strlen(str) - 1;
        
        while (h > l) 
        { 
        if (str[l++] != str[h--]) 
            { 
                flag = 1; 
                break; 
            } 
        }
    
    if(flag)
    printf("no\n");
    else
    printf("yes\n");
        
    }
    
    return 0; 
}