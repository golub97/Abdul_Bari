#include <iostream>
using namespace std;

void Merge(int *array, int left, int mid, int right)
{
    int size_left  = mid - left + 1;
    int size_right = right - mid;
    
    //temporary arrays
    int *left_array = new int[size_left];
    int *right_array = new int[size_right];
    
    for(int i = 0; i < size_left; i++)
        left_array[i] = array[left + i];
    for(int i = 0; i < size_right; i++)
        right_array[i] = array[mid + i + 1];
        
    int left_part_index = 0;
    int right_part_index = 0;
    int main_array_index = left; // Initial index of merged array 
     
    while((left_part_index < size_left) && (right_part_index < size_right))
    {
        if(left_array[left_part_index] <= right_array[right_part_index])
        {
            array[main_array_index] = left_array[left_part_index];
            left_part_index++;
        }
        else
        {
            array[main_array_index] = right_array[right_part_index];
            right_part_index++;
        }
        main_array_index++;
    }
    
    for(; left_part_index < size_left; left_part_index++)
        array[main_array_index++] = left_array[left_part_index];
    for(; right_part_index < size_right; right_part_index++)
        array[main_array_index++] = right_array[right_part_index];
}       

void MergeSort(int *array, int begin, int end)
{
    if(begin >= end)
        return;
    
    int mid = begin + (end-begin)/2;
    
    MergeSort(array, begin, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, begin, mid, end);
}

void print(int const *array, int const size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[] = {1, 10, 7, 15, 4, 22, 33, 44, 3, 88, 9, 55, 49};
    int size = sizeof(array)/sizeof(array[0]);
    
    print(array, size);
    
    MergeSort(array, 0, size-1);
    
    print(array, size);

    return 0;
}
