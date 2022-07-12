#include <iostream>

using namespace std;

class MaxHeap // A class for Max Heap
{
    private:
        int *harr;     // pointer to array of elements in heap
        int capacity;  // maximum possible size of max heap
        int heap_size; // Current number of elements in max heap
    public:
        MaxHeap(int capacity); //Constructor 
        
        //to get index of parent
        int parent(int i) { return (i-1)/2; }
  
        // to get index of left child of node at index i
        int left(int i) { return (2*i + 1); }
  
        // to get index of right child of node at index i
        int right(int i) { return (2*i + 2); }
        
        // Returns the minimum key (key at root) from max heap
        int getMin() { return harr[0]; }
  
        // Deletes a key stored at index i
        void deleteKey(int i);
  
        // Inserts a new key 'k'
        void insertKey(int k);
        
        int  get_heap_size(void)    { return heap_size; }
        int* get_heap_pointer(void) { return harr; }
        
};

// Constructor: Builds a heap from a given array a[] of given size
MaxHeap::MaxHeap(int capacity)
{
    heap_size = 0;
    this->capacity = capacity;
    harr = new int[capacity];
}

// Inserts a new key 'k'
void MaxHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
    
    harr[heap_size++] = k;
    int index = heap_size - 1; //index of new element
    int parent_index = parent(index); //Index strarts from 0, that's why we have -1
    
    while((index != 0) && (harr[index] > harr[parent_index]))
    {
        harr[index]^=harr[parent_index]^=harr[index]^=harr[parent_index]; //swap to elements
        index = parent(index);
        parent_index = parent(parent_index);
    }
}

int main()
{
    int array[] = {10, 20, 15, 30, 40};
    int size = sizeof(array)/sizeof(array[0]);
    MaxHeap heap(size);
    
    for(int i = 0; i < size; i ++)
        heap.insertKey(array[i]);
    
    for(int i = 0; i < heap.get_heap_size(); i++)
    {
        cout << heap.get_heap_pointer()[i] << " ";
    }
    
    return 0;
}
