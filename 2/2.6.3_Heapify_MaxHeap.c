#include <iostream>
using namespace std;
// C++ program for implementation of Heap Sort

// To heapify a subtree rooted with node i
// which is an index in arr[]. 
// n is size of heap
void Heapify(int *arr, int n, int i)
{
    // Initialize largest as root
    int largest = i; 
    
    //left child
    int left  = i*2 + 1;
    
    //right child
    int right = i*2 + 2;
    
    // If left child is larger than root
    if((left < n) && (arr[left] > arr[largest]))
        largest = left;
        
    // If right child is larger than largest 
    if((right < n) && (arr[right] > arr[largest]))
        largest = right;
        
    // If largest is not root
    if(largest != i)
    {
        arr[largest]^=arr[i]^=arr[largest]^=arr[i];
        
        // Recursively heapify the affected 
        // sub-tree
        Heapify(arr, n, largest);
    }
}

// A utility function to print array of size n 
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = { 10, 20, 15, 30, 40 }; //assumption that is complete binary tree presented by an array
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printArray(arr, n);
    
    for(int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);
    
    printArray(arr, n);

    return 0;
}
