#include <iostream>

using namespace std;

int binary_search(int array[], int size, int target)
{
    int start = 0, end = size - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (array[mid] < target)
            start = mid + 1;
        else
            end = mid;
    }
    
    return (array[start] == target) ? start: -1;
}

int main()
{
    //! Binary Search
    int target = 12, array[] = {-1, 0, 3, 4, 5, 9, 12}, size = sizeof(array) / sizeof(array[0]), index = binary_search(array, size, target);

    //! Display output
    cout << "The target " << target << " is located at index " << index << endl;
}
