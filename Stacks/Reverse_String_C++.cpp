#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
 
// define default capacity of the stack
#define SIZE 10
 
// Class for stack
class stack
{
    char *arr;
    int top;
    int capacity;
 
public:
    stack(int size = SIZE);     // constructor
    ~stack();                   // destructor
 
    void push(int);
    char pop();
    char peek();
 
    int size();
    bool isEmpty();
    bool isFull();
};
 
// Constructor to initialize stack
stack::stack(int size)
{
    arr = new char[size];
    capacity = size;
    top = -1;
}
 
// Destructor to free memory allocated to the stack
stack::~stack()
{
    delete[] arr;
}
 
// Utility function to add an element x in the stack
void stack::push(int x)
{
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    arr[++top] = x;
}
 
// Utility function to pop top element from the stack
char stack::pop()
{
    // check for stack underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}
 
// Utility function to return top element in a stack
char stack::peek()
{
    if (!isEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}
 
// Utility function to return the size of the stack
int stack::size()
{
    return top + 1;
}
 
// Utility function to check if the stack is empty or not
bool stack::isEmpty()
{
    return top == -1;    // or return size() == 0;
}
 
// Utility function to check if the stack is full or not
bool stack::isFull()
{
    return top == capacity - 1;    // or return size() == capacity;
}

void reverse(char str[])  
{  
    // Create a stack of capacity  
    //equal to length of string  
    int n = strlen(str);  
    stack pt(50);  
  
    // Push all characters of string to stack  
    int i;  
    for (i = 0; i < n; i++)  
        pt.push(str[i]);  
  
    // Pop all characters of string and  
    // put them back to str  
    for (i = 0; i < n; i++)  
        str[i] = pt.pop();  
}  
 
int main()
{
    char str[] = "Reverse Me";  
  
    reverse(str);  
    cout << "Reversed string is " << str;  
  
    return 0;  
}