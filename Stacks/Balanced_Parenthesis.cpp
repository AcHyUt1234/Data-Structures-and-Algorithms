#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool Parchecker(string expr)
{
    stack <int> s;
    char x;
    
    for(int i=0;i<expr.length();i++)
    {
        if(expr[i]=='(' || expr[i]=='{' || expr[i]=='[')
        {
            s.push(expr[i]);
            continue;
        }
        
        if(s.empty())
        return false;
        
        switch(expr[i])
        {
            case ')': x = s.top();
            s.pop();
            if(x == '{' || x == '[')
            return false;
            break;
            
            case '}': x = s.top();
            s.pop();
            if(x == '(' || x == '[')
            return false;
            break;
            
            case ']': x = s.top();
            s.pop();
            if(x == '{' || x == '(')
            return false;
            break;
        }
    }
    
    return (s.empty());
}

int main() 
{
	stack <int> s;
	int testcase;
	scanf("%d", &testcase);
	
	while(testcase--)
	{
	    char str[100];
	    scanf("%s", &str);
	
	    if(Parchecker(str))
	        cout<<"Balanced\n";
	    else
	        cout<<"Not Balanced\n";
	}
	
	return 0;
}