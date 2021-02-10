#include <iostream> 
  
using namespace std; 
  
// To heapify a subtree rooted with node i which is 
// an index in arr[]. N is size of heap 
void heapify(int arr[], int k, int i) 
{ 
    int smallest = i; // Initialize smallest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < k && arr[l] < arr[smallest]) 
        smallest = l; 
  
    // If right child is larger than largest so far 
    if (r < k && arr[r] < arr[smallest]) 
        smallest = r; 
  
    // If largest is not root 
    if (smallest != i)
    { 
        swap(arr[i], arr[smallest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, k, smallest); 
    } 
} 
  
// Function to build a Min-Heap from the given array 
void buildHeap(int arr[], int k) 
{ 
    // Index of last non-leaf node 
    int startIdx = (k / 2) - 1; 
  
    // Perform reverse level order traversal 
    // from last non-leaf node and heapify 
    // each node 
    for (int i = startIdx; i >= 0; i--) 
    { 
        heapify(arr, k, i); 
    } 
} 

void FirstKelements(int arr[],int size,int k)
{
    // Creating Min Heap for given
    // array with only k elements
    buildHeap(arr, k);
 
    // Loop For each element in array
    // after the kth element
    for (int i = k; i < size; i++) 
    {
        // if current element is smaller 
        // than minimum element, do nothing 
        // and continue to next element
        if (arr[0] > arr[i])
            continue;
 
        // Otherwise Change minimum element to 
        // current element, and call heapify to
        // restore the heap property
        else 
        {
            arr[0] = arr[i];
            heapify(arr, k, 0);
        }
    }
    // Now min heap contains k maximum
    // elements, Iterate and print
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
}
  
// A utility function to print the array 
// representation of Heap 
void printHeap(int arr[], int n) 
{ 
    cout << "Array representation of Heap is:\n"; 
  
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 

int main() 
{ 
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 4;
  
    FirstKelements(arr, n, k); 

  
    return 0; 
} 