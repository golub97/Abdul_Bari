#include <stdio.h>

int BinSearch(int* array, int length, int key)
{
    int l = 0;
    int r = length - 1;
    int midd = 0;
    
    while(l <= r)
    {
        midd = (r+l)/2; //alternative and better way int mid = low + (high – low)/2;
                        //current implementation fails if the sum of low and high is greater than the maximum positive int value(231 – 1 ).
                        //The sum overflows to a negative value and the value stays negative when divided by 2. 
        
        if(key == array[midd])
            return array[midd];
        if(key < array[midd])
            r = midd-1;
        else
            l = midd + 1;
    };
    return -1;
}

int main()
{
    int array[] = {1, 3, 5, 9, 10, 16, 22, 25, 30, 35, 40, 42, 45, 47};
    int size = sizeof(array)/sizeof(int);
    int key = 0;
    
    if(BinSearch(array, size, key) == -1)
        printf("Element %d not found \n", key);
    else
        printf("Element %d found \n", key);

    return 0;
}

