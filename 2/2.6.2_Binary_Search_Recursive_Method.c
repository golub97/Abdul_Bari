#include <stdio.h>

int mid = 0;

int RBinSearch(int* array, int l, int r, int key)
{
    if(r >= l)
    {
        int mid = l + (r - l) / 2;
        
        // If the element is present at the middle
        // itself
        if (array[mid] == key)
            return mid;
            
        if(key < array[mid])
            return RBinSearch(array, l, mid - 1, key);
        else
            return RBinSearch(array, mid+1, r, key);
    }
    
    return -1;
}

int main()
{
    int array[] = {1, 3, 5, 9, 10, 16, 22, 25, 30, 35, 40, 42, 45, 47};
    int l = 0;
    int r = sizeof(array)/sizeof(int);
    int key = 9;
    
    for(key = 0; key < 100; key++)
    {
        if(RBinSearch(array, l, r - 1, key) == -1)
            printf("Element %d not found \n", key);
        else
            printf("Element %d found \n", key);
    }
    return 0;
}
