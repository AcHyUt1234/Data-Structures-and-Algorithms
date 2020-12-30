Method 1 - O(n^3)
bool isTriplet(int ar[], int n) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        for (int j = i + 1; j < n; j++) 
        { 
            for (int k = j + 1; k < n; k++) 
            { 
                // Calculate square of array elements 
                int x = ar[i] * ar[i], y = ar[j] * ar[j], z = ar[k] * ar[k]; 
  
                if (x == y + z || y == x + z || z == x + y) 
                    return true; 
            } 
        } 
    } 
  
    // If we reach here, no triplet found 
    return false; 
} 

Method 2 - O(n^2)
bool isTriplet(int arr[], int n) 
{ 
    // Square array elements 
    for (int i = 0; i < n; i++) 
        arr[i] = arr[i] * arr[i]; 
  
    // Sort array elements 
    sort(arr, arr + n); 
  
    // Now fix one element one by one and find the other two elements 
    for (int i = n - 1; i >= 2; i--) 
    { 
        // To find the other two elements, start two index 
        // variables from two corners of the array and move 
        // them toward each other 
        int l = 0; // index of the first element in arr[0..i-1] 
        int r = i - 1; // index of the last element in arr[0..i-1] 
        while (l < r) 
       { 
            // A triplet found 
            if (arr[l] + arr[r] == arr[i]) 
                return true; 
  
            // Else either move 'l' or 'r' 
            (arr[l] + arr[r] < arr[i]) ? l++ : r--; 
        } 
    } 
  
    // If we reach here, then no triplet found 
    return false; 
} 
